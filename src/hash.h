//
// Created by Bohdan Rybak on 24.03.2016.
//

#ifndef DIGSIG_HASH_H
#define DIGSIG_HASH_H

#include "common.h"

message_t pad_message(const message_t& i_message);

block_t hash_round(const block_t& i_prev_hash, const block_t& i_message);

block_t hash(const message_t& i_message);

// To use in Python, hence C convention
extern "C"
  {
  uint64_t hash_file(const char* ip_filename);
  }

#endif //DIGSIG_HASH_H
