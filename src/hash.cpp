//
// Created by Bohdan Rybak on 24.03.2016.
//

#include "hash.h"
#include "misty.h"

message_t pad_message(const message_t& i_message)
  {
  message_t message = i_message;
  message.push_back(0x80);

  size_t len = message.size();
  size_t bytes_to_add = 8 - (len % 8);
  for(size_t i = 0; i < bytes_to_add; i++)
    message.push_back(0x00);

  return message;
  }

block_t hash_round(const block_t& i_prev_hash, const block_t& i_message)
  {
  return encrypt(i_prev_hash ^ i_message, i_prev_hash)
                 ^ i_message
                 ^ i_prev_hash;
  }
