//
// Created by Bohdan Rybak on 21.03.2016.
//
#include "misty.h"

mblock_t get_round_key(const block_t& i_key, size_t i_round)
  {
  mblock_t left, right;
  mblock_t inverted_left, inverted_right;

  std::copy(i_key.rbegin() + misty_block_size, i_key.rend(), left.begin());
  std::copy(i_key.rbegin(), i_key.rbegin() + misty_block_size, right.begin());

   switch(i_round)
    {
    case 0:
      return left;

    case 1:
      return right;

    case 2:
      for(size_t i = 0; i < right.size(); i++)
        inverted_right[i] = ~right[i];
      return inverted_right;

    case 3:
      for(size_t i = 0; i < left.size(); i++)
        inverted_left[i] = ~left[i];
      return inverted_left;

    default:
      throw std::logic_error("Wrong round number");
    }
  }

block_t encrypt(const block_t &i_message, const block_t &i_key)
  {
  return block_t();
  }

