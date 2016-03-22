//
// Created by Bohdan Rybak on 22.03.2016.

#ifndef DIGSIG_BITWISE_H
#define DIGSIG_BITWISE_H

#include <limits>
#include "common.h"

block_t merge_mblocks(mblock_t i_low, mblock_t i_high);
mblock_t block_high(block_t i_block);
mblock_t block_low(block_t i_block);


#endif //DIGSIG_BITWISE_H
