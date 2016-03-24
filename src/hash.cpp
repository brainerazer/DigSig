//
// Created by Bohdan Rybak on 24.03.2016.
//

#include <iostream>
#include <fstream>
#include "hash.h"
#include "misty.h"

namespace
  {
      typedef std::vector<block_t> hash_input_t;

      hash_input_t convert_padded_message(const message_t& i_message)
        {
        hash_input_t result;
        for(size_t i = 0; i < i_message.size(); i += 8)
        {
          block_t block = 0;
          for (size_t j = 0; j < 8; j++) // todo rewrite into a separate function
            {
            block |= ((block_t) i_message[i + j]) << (j * 8);
            }
          result.push_back(block);
        }

        return result;
        }
  }

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

block_t hash(const message_t& i_message)
  {
  message_t padded_message = pad_message(i_message);
  hash_input_t hash_input = convert_padded_message(padded_message);

  block_t H = 0;

  for(block_t block : hash_input)
    {
    H = hash_round(H, block);
    }

  return H;
  }

// Very inefficient implementation due to copying file into memory,
// albeit very quick to write.
// Should be optimized later
uint64_t hash_file(const char* ip_filename)
  {
  std::ifstream in(ip_filename, std::ios::binary|std::ios::ate); // open at the end of the file
  auto pos = in.tellg();
  std::vector<uint8_t> result(pos);

  in.seekg(0, std::ios::beg);
  in.read(reinterpret_cast<char*>(&result[0]), pos);

  return hash(result);
  }