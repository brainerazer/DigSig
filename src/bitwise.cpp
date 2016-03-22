//
// Created by Bohdan Rybak on 22.03.2016.
//

#include "bitwise.h"

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