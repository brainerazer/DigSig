//
// Created by Bohdan Rybak on 24.03.2016.
//

#include "catch.hpp"

#include "../src/common.h"
#include "../src/hash.h"

TEST_CASE("Test message padding", "[hash]")
  {
  message_t message_1(8, 0xff); // should pad to 16 bytes
  message_t message_2(16, 0xff); // should pad to 24 bytes

  message_t message_3(13, 0xff); // should pad to 16 bytes
  message_t message_4(17, 0xff); // should pad to 24 bytes


  SECTION("Pads if message length divides by 8 bytes")
    {
    REQUIRE(pad_message(message_1).size() == 16);
    REQUIRE(pad_message(message_2).size() == 24);
    }

  SECTION("Pads if message length does not divide by 8 bytes")
    {
    REQUIRE(pad_message(message_3).size() == 16);
    REQUIRE(pad_message(message_4).size() == 24);
    }

  SECTION("Adds correct padding bits")
    {
    REQUIRE(pad_message(message_1)[8] == 0x80);
    REQUIRE(pad_message(message_4)[17] == 0x80);
    }
  }

TEST_CASE("Test a single hash round", "[hash]")
  {
  block_t prev_hash = 0x843D5BDDA757B575;
  block_t message = 0x4E363974696A5952;
  block_t ground_truth_hash = 0x899C03739A99EAA7;

  block_t result = hash_round(prev_hash, message);
  REQUIRE(result == ground_truth_hash);
  }

TEST_CASE("Test hash overall", "[hash]")
  {
  message_t i_message =
          {0x36, 0x73, 0x59, 0x4F, 0x47, 0x39, 0x61, 0x4E,
           0x52, 0x59, 0x6A, 0x69, 0x74, 0x39, 0x36, 0x4E,
           0x78, 0x2B, 0x49, 0x4D, 0x53, 0x36, 0x78, 0x41,
           0x4B, 0x6C, 0x4C, 0x58, 0x4D, 0x68, 0x62, 0x73,
           0x0D ,0x0A};

  block_t ground_truth_hash = 0x323E3502DE41AF2F;

  REQUIRE(hash(i_message) == ground_truth_hash);
  }