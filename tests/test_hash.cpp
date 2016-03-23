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

  }