//
// Created by Bohdan Rybak on 22.03.2016.
//

#include "bitwise.h"

#include <climits>
#include <cassert>


block_t merge_mblocks(mblock_t i_low, mblock_t i_high)
  {
  return (((block_t) i_high) << misty_block_size) | ((block_t) i_low);
  }

mblock_t block_high(block_t i_block)
  {
  return i_block >> 32;
  }

mblock_t block_low(block_t i_block)
  {
  mblock_t mask = std::numeric_limits<mblock_t>::max();
  return mask & i_block;
  }

uint8_t get_byte_32(uint32_t i_num, size_t i_byte)
  {
  return (i_num >> (i_byte * 8)) & 0xFF;
  }

uint32_t rotl32 (uint32_t n, unsigned int c)
  {
  const unsigned int mask = (CHAR_BIT * sizeof(n) - 1);

  assert ((c <= mask) && "rotate by type width or more");
  c &= mask;  // avoid undef behaviour with NDEBUG.  0 overhead for most types / compilers
  return (n << c) | (n >> ((-c) & mask));
  }