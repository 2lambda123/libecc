/*
 *  Copyright (C) 2022 - This file is part of libecc project
 *
 *  Authors:
 *      Arnaud EBALARD <arnaud.ebalard@ssi.gouv.fr>
 *      Ryad BENADJILA <ryadbenadjila@gmail.com>
 *
 *  This software is licensed under a dual BSD and GPL v2 license.
 *  See LICENSE file at the root folder of the project.
 */
#ifndef __DBIGN_TEST_VECTORS_H__
#define __DBIGN_TEST_VECTORS_H__

#if defined(WITH_HASH_BELT_HASH) && defined(WITH_CURVE_BIGN256V1)
/************************************************/
static const u8 dbign_1_test_vectors_priv_key[] = {
	0x69, 0xe2, 0x73, 0xc2, 0x5f, 0x23, 0x79, 0x0c, 0x9e, 0x42, 0x32, 0x07, 0xed, 0x1f, 0x28, 0x34, 0x18, 0xf2, 0x74, 0x9c, 0x32, 0xf0, 0x33, 0x45, 0x67, 0x39, 0x73, 0x4b, 0xb8, 0xb5, 0x66, 0x1f,
 };
static const u8 dbign_1_test_vectors_expected_sig[] = {
	0x19, 0xd3, 0x2b, 0x7e, 0x01, 0xe2, 0x5b, 0xae, 0x4a, 0x70, 0xeb, 0x6b, 0xca, 0x42, 0x60, 0x2c,
	0xca, 0x6a, 0x13, 0x94, 0x44, 0x51, 0xbc, 0xc5, 0xd4, 0xc5, 0x4c, 0xfd, 0x87, 0x37, 0x61, 0x9c, 0x32, 0x8b, 0x8a, 0x58, 0xfb, 0x9c, 0x68, 0xfd, 0x17, 0xd5, 0x69, 0xf7, 0xd0, 0x64, 0x95, 0xfb,
 };
static const u8 dbign_1_test_vectors_adata[] = {
	0x00, 0x0b, 0x00, 0x00,
	0x06, 0x09, 0x2A, 0x70, 0x00, 0x02, 0x00, 0x22, 0x65, 0x1F, 0x51,
};

static const ec_test_case dbign_1_test_case = {
        .name = "DBIGN-BELT-HASH/dbign256v1 1",
        .ec_str_p = &bign256v1_str_params,
        .priv_key = dbign_1_test_vectors_priv_key,
        .priv_key_len = sizeof(dbign_1_test_vectors_priv_key),
        .nn_random = NULL,
        .hash_type = BELT_HASH,
        .msg = "\xB1\x94\xBA\xC8\x0A\x08\xF5\x3B\x36\x6D\x00\x8E\x58",
        .msglen = 13,
        .sig_type = DBIGN,
        .exp_sig = dbign_1_test_vectors_expected_sig,
        .exp_siglen = sizeof(dbign_1_test_vectors_expected_sig),
	.adata = dbign_1_test_vectors_adata,
	.adata_len = sizeof(dbign_1_test_vectors_adata)
};

/********************************************************************/
static const u8 dbign_2_test_vectors_priv_key[] = {
	0x69, 0xe2, 0x73, 0xc2, 0x5f, 0x23, 0x79, 0x0c, 0x9e, 0x42, 0x32, 0x07, 0xed, 0x1f, 0x28, 0x34, 0x18, 0xf2, 0x74, 0x9c, 0x32, 0xf0, 0x33, 0x45, 0x67, 0x39, 0x73, 0x4b, 0xb8, 0xb5, 0x66, 0x1f,
 };
static const u8 dbign_2_test_vectors_expected_sig[] = {
	0x2a, 0x0e, 0xf2, 0x4b, 0xa6, 0x2d, 0x63, 0xa3, 0x34, 0x10, 0x3f, 0x47, 0x0d, 0xc7, 0x55, 0xeb,
	0x2c, 0x51, 0xba, 0x3d, 0x57, 0xaa, 0x4e, 0xfe, 0xd5, 0x61, 0x76, 0x19, 0x04, 0xf9, 0x39, 0x9e, 0x0f, 0xf6, 0x18, 0x04, 0xfb, 0x46, 0xec, 0xa1, 0x74, 0xe1, 0xdd, 0xd9, 0xe5, 0x5e, 0x25, 0x64,
 };
static const u8 dbign_2_test_vectors_adata[] = {
	0x00, 0x0b, 0x00, 0x17,
	0x06, 0x09, 0x2A, 0x70, 0x00, 0x02, 0x00, 0x22, 0x65, 0x1F, 0x51,
	0xBE, 0x32, 0x97, 0x13, 0x43, 0xFC, 0x9A, 0x48, 0xA0, 0x2A, 0x88, 0x5F, 0x19, 0x4B, 0x09, 0xA1, 0x7E, 0xCD, 0xA4, 0xD0, 0x15, 0x44, 0xAF,
};

static const ec_test_case dbign_2_test_case = {
        .name = "DBIGN-BELT-HASH/dbign256v1 2",
        .ec_str_p = &bign256v1_str_params,
        .priv_key = dbign_2_test_vectors_priv_key,
        .priv_key_len = sizeof(dbign_2_test_vectors_priv_key),
        .nn_random = NULL,
        .hash_type = BELT_HASH,
        .msg = "\xB1\x94\xBA\xC8\x0A\x08\xF5\x3B\x36\x6D\x00\x8E\x58\x4A\x5D\xE4\x85\x04\xFA\x9D\x1B\xB6\xC7\xAC\x25\x2E\x72\xC2\x02\xFD\xCE\x0D\x5B\xE3\xD6\x12\x17\xB9\x61\x81\xFE\x67\x86\xAD\x71\x6B\x89\x0B",
        .msglen = 48,
        .sig_type = DBIGN,
        .exp_sig = dbign_2_test_vectors_expected_sig,
        .exp_siglen = sizeof(dbign_2_test_vectors_expected_sig),
	.adata = dbign_2_test_vectors_adata,
	.adata_len = sizeof(dbign_2_test_vectors_adata)
};

/********************************************************************/
static const u8 dbign_3_test_vectors_priv_key[] = {
	0xb3, 0x8a, 0x57, 0x70, 0xaa, 0xe8, 0x97, 0x73, 0x1a, 0xe3, 0x69, 0xaa, 0x48, 0x91, 0xf3, 0x14, 0xd4, 0xae, 0x76, 0x94, 0x29, 0xf3, 0xde, 0x94, 0xeb, 0x9b, 0x36, 0xdf, 0x79, 0x89, 0x62, 0x79,
 };

static const u8 dbign_3_test_vectors_expected_sig[] = {
	0x3d, 0xcf, 0xf8, 0x86, 0x87, 0xa9, 0x8a, 0xbb, 0x01, 0xce, 0x2d, 0xe8, 0x3e, 0x3a, 0x65, 0xeb,
	0x69, 0xd1, 0x6a, 0x47, 0x50, 0x87, 0x50, 0xfb, 0x6f, 0x18, 0x64, 0x2c, 0x1b, 0x48, 0xb4, 0xaf, 0xff, 0xcd, 0x59, 0xcf, 0xd9, 0x98, 0x6f, 0xe9, 0xf2, 0xbb, 0xea, 0x99, 0xb9, 0x65, 0xb0, 0x1b,
 };
static const u8 dbign_3_test_vectors_adata[] = {
	0x00, 0x0b, 0x00, 0x00,
	0x06, 0x09, 0x2A, 0x70, 0x00, 0x02, 0x00, 0x22, 0x65, 0x1F, 0x51,
};

static const ec_test_case dbign_3_test_case = {
        .name = "DBIGN-BELT-HASH/dbign256v1 3",
        .ec_str_p = &bign256v1_str_params,
        .priv_key = dbign_3_test_vectors_priv_key,
        .priv_key_len = sizeof(dbign_3_test_vectors_priv_key),
        .nn_random = NULL,
        .hash_type = BELT_HASH,
        .msg = "\xB1\x94\xBA\xC8\x0A\x08\xF5\x3B\x36\x6D\x00\x8E\x58\x4A\x5D\xE4\x85\x04\xFA\x9D\x1B\xB6\xC7\xAC\x25\x2E\x72\xC2\x02\xFD\xCE\x0D\x5B\xE3\xD6\x12\x17\xB9\x61\x81\xFE\x67\x86\xAD\x71\x6B\x89\x0B",
        .msglen = 48,
        .sig_type = DBIGN,
        .exp_sig = dbign_3_test_vectors_expected_sig,
        .exp_siglen = sizeof(dbign_3_test_vectors_expected_sig),
	.adata = dbign_3_test_vectors_adata,
	.adata_len = sizeof(dbign_3_test_vectors_adata)
};
#endif

#if defined(WITH_HASH_BASH384) && defined(WITH_CURVE_BIGN384V1)
/********************************************************************/
static const u8 dbign_4_test_vectors_priv_key[] = {
        0x0e, 0xb5, 0x93, 0x2d, 0x23, 0x1a, 0xe1, 0x37, 0x61, 0x41, 0x80, 0xec, 0x3b, 0xbe, 0x08, 0x0f, 0x93, 0xba, 0x80, 0x27, 0x8f, 0x05, 0xd8, 0x2f, 0x87, 0x6a, 0xf9, 0xf9, 0xea, 0x0a, 0xf1, 0x9e, 0x6c, 0xa1, 0x6f, 0x21, 0x6c, 0x38, 0x21, 0xdc, 0x72, 0x23, 0x3c, 0x7b, 0xbf, 0x1d, 0xc2, 0x84,
 };
static const u8 dbign_4_test_vectors_expected_sig[] = {
	0xc2, 0xf6, 0x0f, 0x84, 0x00, 0xc1, 0xe4, 0xdd, 0xc4, 0x7f, 0x05, 0xd9, 0x6c, 0x0f, 0xed, 0x1e, 0xe3, 0x0a, 0xb2, 0x29, 0x87, 0x5d, 0xff, 0xb3,
	0xfa, 0xd2, 0xd7, 0x0e, 0xb8, 0x05, 0x56, 0x64, 0x12, 0xff, 0x35, 0xef, 0x62, 0xc0, 0x6f, 0xa6, 0x6b, 0x42, 0x5f, 0x21, 0x30, 0x60, 0x40, 0x9c, 0x6c, 0x06, 0xfc, 0x04, 0xf5, 0x0c, 0x63, 0x7e, 0x84, 0xbb, 0x3e, 0x7a, 0x29, 0x81, 0x51, 0xaa, 0xb1, 0x1a, 0x50, 0xb8, 0xe1, 0x52, 0x91, 0xbc,
      };
static const u8 dbign_4_test_vectors_adata[] = {
        0x00, 0x0b, 0x00, 0x00,
        0x06, 0x09, 0x2A, 0x70, 0x00, 0x02, 0x00, 0x22, 0x65, 0x4d, 0x0c,
};
static const ec_test_case dbign_4_test_case = {
        .name = "BIGN-BASH384/dbign384v1 4",
        .ec_str_p = &bign384v1_str_params,
        .priv_key = dbign_4_test_vectors_priv_key,
        .priv_key_len = sizeof(dbign_4_test_vectors_priv_key),
        .nn_random = NULL,
        .hash_type = BASH384,
        .msg = "\xb1\x94\xba\xc8\x0a\x08\xf5\x3b\x36\x6d\x00\x8e\x58\x4a\x5d\xe4\x85\x04\xfa\x9d\x1b\xb6\xc7\xac\x25\x2e\x72\xc2\x02\xfd\xce\x0d\x5b\xe3\xd6\x12\x17\xb9\x61\x81\xfe\x67\x86\xad\x71\x6b\x89\x0b\x5c\xb0\xc0\xff\x33\xc3\x56\xb8\x35\xc4\x05\xae\xd8\xe0\x7f\x99\xe1\x2b\xdc\x1a\xe2\x82\x57\xec\x70\x3f\xcc\xf0\x95\xee\x8d\xf1\xc1\xab\x76\x38\x9f\xe6\x78\xca\xf7\xc6\xf8\x60\xd5\xbb\x9c",
        .msglen = 95,
        .sig_type = DBIGN,
        .exp_sig = dbign_4_test_vectors_expected_sig,
        .exp_siglen = sizeof(dbign_4_test_vectors_expected_sig),
        .adata = dbign_4_test_vectors_adata,
        .adata_len = sizeof(dbign_4_test_vectors_adata)
};
/********************************************************************/
static const u8 dbign_5_test_vectors_priv_key[] = {
	0x2d, 0x27, 0xc3, 0x89, 0x27, 0x29, 0xfd, 0xb6, 0xf0, 0xee, 0xa7, 0xf8, 0x4e, 0x15, 0x2d, 0x30, 0x24, 0x60, 0xc9, 0x84, 0xde, 0xcb, 0xf6, 0xe6, 0xff, 0x4b, 0xce, 0xfb, 0x89, 0xb1, 0x5d, 0xd2, 0xe8, 0x4d, 0x10, 0xd6, 0x09, 0x92, 0x80, 0x2d, 0x66, 0x6b, 0xb8, 0x05, 0x5f, 0x31, 0xe1, 0x04,
 };
static const u8 dbign_5_test_vectors_expected_sig[] = {
	0x50, 0x0d, 0x4d, 0x66, 0xd4, 0xa6, 0x8a, 0xfc, 0xbb, 0x1d, 0xa7, 0x04, 0xa8, 0xc3, 0xdb, 0x4d, 0x97, 0xb6, 0x2f, 0x71, 0xe8, 0xcb, 0xfd, 0x06,
	0x27, 0xa8, 0x45, 0x1b, 0x30, 0x3f, 0x1b, 0x00, 0x84, 0xb3, 0xab, 0xf0, 0x21, 0x6e, 0x8c, 0x1d, 0x2f, 0x24, 0x75, 0x78, 0x0a, 0x50, 0x6d, 0xc8, 0x29, 0x7e, 0xb7, 0xab, 0x58, 0x73, 0x03, 0xd9, 0x9a, 0x1f, 0x9b, 0x90, 0x7e, 0xec, 0x1a, 0x0d, 0xf8, 0x41, 0x16, 0x53, 0x57, 0xcd, 0x92, 0x6a,
 };
static const u8 dbign_5_test_vectors_adata[] = {
        0x00, 0x0b, 0x00, 0x00,
        0x06, 0x09, 0x2A, 0x70, 0x00, 0x02, 0x00, 0x22, 0x65, 0x4d, 0x0c,
};
static const ec_test_case dbign_5_test_case = {
        .name = "BIGN-BASH384/dbign384v1 5",
        .ec_str_p = &bign384v1_str_params,
        .priv_key = dbign_5_test_vectors_priv_key,
        .priv_key_len = sizeof(dbign_5_test_vectors_priv_key),
        .nn_random = NULL,
        .hash_type = BASH384,
        .msg = "\xb1\x94\xba\xc8\x0a\x08\xf5\x3b\x36\x6d\x00\x8e\x58\x4a\x5d\xe4\x85\x04\xfa\x9d\x1b\xb6\xc7\xac\x25\x2e\x72\xc2\x02\xfd\xce\x0d\x5b\xe3\xd6\x12\x17\xb9\x61\x81\xfe\x67\x86\xad\x71\x6b\x89\x0b\x5c\xb0\xc0\xff\x33\xc3\x56\xb8\x35\xc4\x05\xae\xd8\xe0\x7f\x99\xe1\x2b\xdc\x1a\xe2\x82\x57\xec\x70\x3f\xcc\xf0\x95\xee\x8d\xf1\xc1\xab\x76\x38\x9f\xe6\x78\xca\xf7\xc6\xf8\x60\xd5\xbb\x9c\x4f",
        .msglen = 96,
        .sig_type = DBIGN,
        .exp_sig = dbign_5_test_vectors_expected_sig,
        .exp_siglen = sizeof(dbign_5_test_vectors_expected_sig),
        .adata = dbign_5_test_vectors_adata,
        .adata_len = sizeof(dbign_5_test_vectors_adata)
};

#endif

#if defined(WITH_HASH_BASH512) && defined(WITH_CURVE_BIGN512V1)
/********************************************************************/
static const u8 dbign_6_test_vectors_priv_key[] = {
        0xb8, 0xb9, 0x4a, 0xd2, 0xe5, 0x05, 0x02, 0xc5, 0x21, 0xe8, 0x8f, 0x1b, 0xcf, 0x97, 0x0b, 0x1b, 0x47, 0x78, 0x02, 0x31, 0x5b, 0xfe, 0x1f, 0x71, 0xd8, 0x55, 0x71, 0xa2, 0xd1, 0xc1, 0x90, 0x60, 0xba, 0xa2, 0xf1, 0xe0, 0x7d, 0x73, 0xd5, 0x2f, 0x37, 0x31, 0x0b, 0x04, 0x02, 0x3a, 0xbf, 0x33, 0x63, 0xb5, 0xf2, 0x95, 0x2a, 0x62, 0x17, 0xa4, 0x8a, 0x56, 0xf4, 0x3e, 0x35, 0x96, 0xc0, 0xbe,
 };
static const u8 dbign_6_test_vectors_expected_sig[] = {
	0x6e, 0x40, 0xef, 0x8f, 0xf9, 0x9e, 0x26, 0x86, 0xc8, 0x88, 0x53, 0xbb, 0x89, 0xd4, 0xbb, 0x92, 0x33, 0xe8, 0x07, 0x36, 0x5a, 0x32, 0x57, 0x57, 0x1d, 0x53, 0x68, 0xbf, 0x5d, 0x83, 0xd1, 0x5e,
	0x21, 0x83, 0x5b, 0xd6, 0xfa, 0x3b, 0x3d, 0xae, 0x93, 0x30, 0xc2, 0x79, 0x6c, 0x80, 0x3e, 0xee, 0xc9, 0x70, 0x3a, 0x81, 0xe7, 0x40, 0xfd, 0x6d, 0xd8, 0x51, 0xd0, 0x7d, 0xb9, 0x55, 0x72, 0x6c, 0x60, 0x86, 0x8d, 0x61, 0x4b, 0x23, 0x54, 0xe6, 0xd6, 0x4c, 0xf0, 0xd8, 0xdc, 0x9e, 0xf4, 0x79, 0x63, 0xf7, 0x0b, 0xb0, 0xd6, 0xf4, 0x21, 0x67, 0x54, 0x56, 0xbf, 0xbb, 0xb2, 0x03, 0xf2, 0x43,
 };
static const u8 dbign_6_test_vectors_adata[] = {
        0x00, 0x0b, 0x00, 0x00,
        0x06, 0x09, 0x2A, 0x70, 0x00, 0x02, 0x00, 0x22, 0x65, 0x4d, 0x0d,
};
static const ec_test_case dbign_6_test_case = {
        .name = "BIGN-BASH512/dbign512v1 6",
        .ec_str_p = &bign512v1_str_params,
        .priv_key = dbign_6_test_vectors_priv_key,
        .priv_key_len = sizeof(dbign_6_test_vectors_priv_key),
        .nn_random = NULL,
        .hash_type = BASH512,
        .msg = "\xb1\x94\xba\xc8\x0a\x08\xf5\x3b\x36\x6d\x00\x8e\x58\x4a\x5d\xe4\x85\x04\xfa\x9d\x1b\xb6\xc7\xac\x25\x2e\x72\xc2\x02\xfd\xce\x0d\x5b\xe3\xd6\x12\x17\xb9\x61\x81\xfe\x67\x86\xad\x71\x6b\x89\x0b\x5c\xb0\xc0\xff\x33\xc3\x56\xb8\x35\xc4\x05\xae\xd8\xe0\x7f",
        .msglen = 63,
        .sig_type = DBIGN,
        .exp_sig = dbign_6_test_vectors_expected_sig,
        .exp_siglen = sizeof(dbign_6_test_vectors_expected_sig),
        .adata = dbign_6_test_vectors_adata,
        .adata_len = sizeof(dbign_6_test_vectors_adata)
};
/********************************************************************/
static const u8 dbign_7_test_vectors_priv_key[] = {
	0x33, 0x0e, 0xea, 0x5c, 0xcd, 0xc8, 0x96, 0x5a, 0x4c, 0x05, 0xfc, 0x9c, 0x44, 0xde, 0x84, 0xd4, 0x53, 0x45, 0xd8, 0xdd, 0x5e, 0x04, 0xc3, 0x02, 0xff, 0xb9, 0x35, 0x76, 0xbd, 0x20, 0x7a, 0x56, 0x6c, 0x00, 0x7c, 0x95, 0x3b, 0x1f, 0x95, 0xb9, 0x88, 0x7c, 0x2d, 0x64, 0x14, 0x7a, 0x57, 0xf1, 0xeb, 0x0f, 0xe1, 0x02, 0x3e, 0x4f, 0xd5, 0x1f, 0xb3, 0xd5, 0xa8, 0xea, 0xd4, 0x88, 0x01, 0xa9,
 };
static const u8 dbign_7_test_vectors_expected_sig[] = {
	0x3d, 0x2e, 0x3b, 0x3e, 0x2a, 0x2a, 0xed, 0x58, 0x34, 0x7e, 0x87, 0xf2, 0x8c, 0xf8, 0xde, 0xe9, 0xd3, 0xfd, 0x6f, 0x91, 0x07, 0xe6, 0xf9, 0x0b, 0xd6, 0x75, 0x4a, 0x37, 0xe7, 0x8d, 0x8f, 0x63,
	0xfb, 0x5c, 0xc4, 0xdc, 0x39, 0xfb, 0x56, 0x7f, 0xa8, 0x54, 0x1b, 0x7f, 0x62, 0x86, 0x42, 0x02, 0xbb, 0x53, 0x62, 0x6c, 0xb2, 0x40, 0x70, 0x14, 0xea, 0x40, 0xef, 0x04, 0xbd, 0x20, 0xae, 0x19, 0x21, 0x39, 0xae, 0x24, 0x76, 0x9b, 0x20, 0x00, 0x9b, 0x7c, 0x99, 0x75, 0x1e, 0xbc, 0xef, 0x52, 0xf6, 0xfe, 0xfa, 0xe0, 0xc3, 0xaa, 0xd8, 0xf1, 0x2e, 0x78, 0xb2, 0x5e, 0x9b, 0xcc, 0x21, 0xec,
 };
static const u8 dbign_7_test_vectors_adata[] = {
        0x00, 0x0b, 0x00, 0x00,
        0x06, 0x09, 0x2A, 0x70, 0x00, 0x02, 0x00, 0x22, 0x65, 0x4d, 0x0d,
};
static const ec_test_case dbign_7_test_case = {
        .name = "BIGN-BASH512/dbign512v1 7",
        .ec_str_p = &bign512v1_str_params,
        .priv_key = dbign_7_test_vectors_priv_key,
        .priv_key_len = sizeof(dbign_7_test_vectors_priv_key),
        .nn_random = NULL,
        .hash_type = BASH512,
        .msg = "\xb1\x94\xba\xc8\x0a\x08\xf5\x3b\x36\x6d\x00\x8e\x58\x4a\x5d\xe4\x85\x04\xfa\x9d\x1b\xb6\xc7\xac\x25\x2e\x72\xc2\x02\xfd\xce\x0d\x5b\xe3\xd6\x12\x17\xb9\x61\x81\xfe\x67\x86\xad\x71\x6b\x89\x0b\x5c\xb0\xc0\xff\x33\xc3\x56\xb8\x35\xc4\x05\xae\xd8\xe0\x7f\x99",
        .msglen = 64,
        .sig_type = DBIGN,
        .exp_sig = dbign_7_test_vectors_expected_sig,
        .exp_siglen = sizeof(dbign_7_test_vectors_expected_sig),
        .adata = dbign_7_test_vectors_adata,
        .adata_len = sizeof(dbign_7_test_vectors_adata)
};

#endif


/************************************************/
#define DBIGN_ALL_TESTS() \
        &dbign_1_test_case, \
        &dbign_2_test_case, \
	&dbign_3_test_case, \
	&dbign_4_test_case, \
	&dbign_5_test_case, \
	&dbign_6_test_case, \
	&dbign_7_test_case,

#endif /* __DBIGN_TEST_VECTORS_H__ */
