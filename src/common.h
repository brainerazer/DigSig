//
// Created by Bohdan Rybak on 21.03.2016.
//

#ifndef DIGSIG_COMMON_H
#define DIGSIG_COMMON_H

#include <array>
const size_t block_size = 64;
const size_t misty_block_size = 32;

typedef unsigned char byte_t;
typedef std::array<byte_t, block_size>         block_t; // 8 bytes
typedef std::array<byte_t, misty_block_size>   mblock_t; // 4 bytes

#endif //DIGSIG_COMMON_H
