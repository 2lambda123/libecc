#include "../lib_ecc_config.h"
#ifdef WITH_HMAC

#include "hmac.h"

int hmac_init(hmac_context *ctx, const u8 *hmackey, u32 hmackey_len, hash_alg_type hash_type)
{
	u8 ipad[MAX_BLOCK_SIZE];
	u8 opad[MAX_BLOCK_SIZE];
 	u8 local_hmac_key[MAX_BLOCK_SIZE];
	unsigned int i, local_hmac_key_len;
	int ret = -1;

	local_memset(local_hmac_key, 0, sizeof(local_hmac_key));
        /* Set ipad and opad to appropriate values */
        local_memset(ipad, 0x36, sizeof(ipad));
        local_memset(opad, 0x5c, sizeof(opad));

        /* Get the hash mapping of the current asked hash function */
        ctx->hash = get_hash_by_type(hash_type);
        if(ctx->hash == NULL){
		ret = -1;
                goto err;
        }

        if(hmackey_len <= ctx->hash->block_size){
                /* The key size is less than the hash function block size */
                local_memcpy(local_hmac_key, hmackey, hmackey_len);
                local_hmac_key_len = hmackey_len;
        }
        else{
                /* The key size is greater than the hash function block size.
                 * We hash it to shorten it.
                 */
                hash_context tmp_ctx;
                /* Check our callback */
                if(hash_mapping_callbacks_sanity_check(ctx->hash)){
			ret = -1;
                        goto err;
                }
                ctx->hash->hfunc_init(&tmp_ctx);
                /* Check our callback */
                if(hash_mapping_callbacks_sanity_check(ctx->hash)){
			ret = -1;
                        goto err;
                }
                ctx->hash->hfunc_update(&tmp_ctx, hmackey, hmackey_len);
                /* Check our callback */
                if(hash_mapping_callbacks_sanity_check(ctx->hash)){
			ret = -1;
                        goto err;
                }
                ctx->hash->hfunc_finalize(&tmp_ctx, local_hmac_key);
                local_hmac_key_len = ctx->hash->digest_size;
        }

        /* Initialize our input and output hash contexts */
        /* Check our callback */
        if(hash_mapping_callbacks_sanity_check(ctx->hash)){
		ret = -1;
                goto err;
        }
        ctx->hash->hfunc_init(&(ctx->in_ctx));
        /* Check our callback */
        if(hash_mapping_callbacks_sanity_check(ctx->hash)){
		ret = -1;
                goto err;
        }
        ctx->hash->hfunc_init(&(ctx->out_ctx));

        /* Update our input context with K^ipad */
        for(i = 0; i < local_hmac_key_len; i++){
                ipad[i] ^= local_hmac_key[i];
        }
        /* Check our callback */
        if(hash_mapping_callbacks_sanity_check(ctx->hash)){
		ret = -1;
                goto err;
        }
        ctx->hash->hfunc_update(&(ctx->in_ctx), ipad, ctx->hash->block_size);
        /* Update our output context with K^opad */
        for(i = 0; i < local_hmac_key_len; i++){
                opad[i] ^= local_hmac_key[i];
        }
        /* Check our callback */
        if(hash_mapping_callbacks_sanity_check(ctx->hash)){
		ret = -1;
                goto err;
        }
        ctx->hash->hfunc_update(&(ctx->out_ctx), opad, ctx->hash->block_size);

	/* Initialize our magic */
	ctx->magic = HMAC_MAGIC;

        ret = 0;
err:
        return ret;
}

int hmac_update(hmac_context *ctx, const u8 *input, u32 ilen)
{
	int ret = -1;

	HMAC_CHECK_INITIALIZED(ctx);

        /* Check our callback */
        if(hash_mapping_callbacks_sanity_check(ctx->hash)){
		ret = -1;
		goto err;
	}
        ctx->hash->hfunc_update(&(ctx->in_ctx), input, ilen);

	ret = 0;
err:
        return ret;
}

int hmac_finalize(hmac_context *ctx, u8 *output, u8 *outlen)
{
	int ret = -1;
	u8 in_hash[MAX_DIGEST_SIZE];

	HMAC_CHECK_INITIALIZED(ctx);
	MUST_HAVE((output != NULL) && (outlen != NULL));

        if((*outlen) < ctx->hash->digest_size){
		ret = -1;
                goto err;
        }
        /* Check our callback */
        if(hash_mapping_callbacks_sanity_check(ctx->hash)){
		ret = -1;
                goto err;
        }
        ctx->hash->hfunc_finalize(&(ctx->in_ctx), in_hash);
        /* Check our callback */
        if(hash_mapping_callbacks_sanity_check(ctx->hash)){
		ret = -1;
                goto err;
        }
        ctx->hash->hfunc_update(&(ctx->out_ctx), in_hash, ctx->hash->digest_size);
        /* Check our callback */
        if(hash_mapping_callbacks_sanity_check(ctx->hash)){
		ret = -1;
                goto err;
        }
        ctx->hash->hfunc_finalize(&(ctx->out_ctx), output);
        *outlen = ctx->hash->digest_size;

	ret = 0;
err:
	/* Clear the hash contexts that could contain sensitive data */
	local_memset(ctx, 0, sizeof(hmac_context));
	/* Uninitialize the context  */
	ctx->magic = 0;
	if(ret){
		*outlen = 0;
	}
	return ret;
}

int hmac(const u8 *hmackey, u32 hmackey_len, hash_alg_type hash_type, const u8 *input, u32 ilen, u8 *output, u8 *outlen)
{
	int ret = -1;
	hmac_context ctx;

	if(hmac_init(&ctx, hmackey, hmackey_len, hash_type)){
		ret = -1;
		goto err;
	}
	if(hmac_update(&ctx, input, ilen)){
		ret = -1;
		goto err;
	}
	if(hmac_finalize(&ctx, output, outlen)){
		ret = -1;
		goto err;
	}

	ret = 0;
err:
	/* Clean our context as it can contain sensitive data */
	local_memset(&ctx, 0, sizeof(hmac_context));
	return ret;
}


#else /* WITH_HMAC */

/*
 * Dummy definition to avoid the empty translation unit ISO C warning
 */
typedef int dummy;
#endif /* WITH_HMAC */
