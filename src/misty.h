//
// Created by Bohdan Rybak on 21.03.2016.
//

#ifndef DIGSIG_ENCRYPT_H
#define DIGSIG_ENCRYPT_H

#include "common.h"

mblock_t get_round_key(const block_t& i_key, size_t i_round); // round in [0..3]
block_t encrypt(const block_t& i_message, const block_t& i_key);

#endif //DIGSIG_ENCRYPT_H
