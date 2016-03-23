//
// Created by Bohdan Rybak on 21.03.2016.
//

#ifndef DIGSIG_COMMON_H
#define DIGSIG_COMMON_H

#include <array>
#include <vector>

const size_t block_size = 64; // bits
const size_t misty_block_size = block_size / 2;

typedef unsigned char byte_t;

typedef uint64_t block_t;
typedef uint32_t mblock_t;

typedef std::vector<byte_t> message_t;

#endif //DIGSIG_COMMON_H
