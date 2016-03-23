//
// Created by Bohdan Rybak on 24.03.2016.
//

#include "hash.h"
#include "misty.h"

block_t hash_round(const block_t& i_prev_hash, const block_t& i_message)
  {
  return encrypt(i_prev_hash ^ i_message, i_prev_hash)
                 ^ i_message
                 ^ i_prev_hash;
  }
