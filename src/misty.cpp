//
// Created by Bohdan Rybak on 21.03.2016.
//
#include "misty.h"
#include "bitwise.h"

mblock_t get_round_key(const block_t& i_key, size_t i_round)
  {
   switch(i_round)
    {
    case 0:
      return block_low(i_key);

    case 1:
      return block_high(i_key);

    case 2:
      return ~block_high(i_key);

    case 3:
      return ~block_low(i_key);

    default:
      throw std::logic_error("Wrong round number");
    }
  }

mblock_t perform_round(const mblock_t& i_left_block, const mblock_t& i_right_block, const mblock_t& i_key)
  {
  return mblock_t();
  }

block_t encrypt(const block_t &i_message, const block_t &i_key)
  {
  return block_t();
  }

