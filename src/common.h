//
// Created by Bohdan Rybak on 21.03.2016.
//

#ifndef DIGSIG_COMMON_H
#define DIGSIG_COMMON_H

#include <array>
const size_t block_size = 64;

typedef unsigned char byte_t;
typedef std::array<byte_t, block_size> block_t; //

#endif //DIGSIG_COMMON_H
