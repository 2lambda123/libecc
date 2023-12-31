/*
 *  Copyright (C) 2017 - This file is part of libecc project
 *
 *  Authors:
 *      Ryad BENADJILA <ryadbenadjila@gmail.com>
 *      Arnaud EBALARD <arnaud.ebalard@ssi.gouv.fr>
 *      Jean-Pierre FLORI <jean-pierre.flori@ssi.gouv.fr>
 *
 *  Contributors:
 *      Nicolas VIVET <nicolas.vivet@ssi.gouv.fr>
 *      Karim KHALFALLAH <karim.khalfallah@ssi.gouv.fr>
 *
 *  This software is licensed under a dual BSD and GPL v2 license.
 *  See LICENSE file at the root folder of the project.
 */
#ifndef __NN_ADD_PUBLIC_H__
#define __NN_ADD_PUBLIC_H__
#include "nn.h"

ATTRIBUTE_WARN_UNUSED_RET int nn_add(nn_t C, nn_src_t A, nn_src_t B);
ATTRIBUTE_WARN_UNUSED_RET int nn_inc(nn_t C, nn_src_t A);
ATTRIBUTE_WARN_UNUSED_RET int nn_sub(nn_t C, nn_src_t A, nn_src_t B);
ATTRIBUTE_WARN_UNUSED_RET int nn_dec(nn_t C, nn_src_t A);
ATTRIBUTE_WARN_UNUSED_RET int nn_mod_add(nn_t C, nn_src_t A, nn_src_t B, nn_src_t P);
ATTRIBUTE_WARN_UNUSED_RET int nn_mod_inc(nn_t C, nn_src_t A, nn_src_t P);
ATTRIBUTE_WARN_UNUSED_RET int nn_mod_sub(nn_t C, nn_src_t A, nn_src_t B, nn_src_t P);
ATTRIBUTE_WARN_UNUSED_RET int nn_mod_dec(nn_t C, nn_src_t A, nn_src_t P);
ATTRIBUTE_WARN_UNUSED_RET int nn_mod_neg(nn_t C, nn_src_t A, nn_src_t P);

#endif /* __NN_ADD_PUBLIC_H__ */
