//
// Created by Bohdan Rybak on 22.03.2016.
//
#include "catch.hpp"

#include "../src/common.h"
#include "../src/misty.h"

TEST_CASE("Round key is generated", "[misty]")
  {
  block_t key ({0x36, 0x73, 0x59, 0x4F, 0x47, 0x39, 0x61, 0x4E});

  REQUIRE_NOTHROW(get_round_key(key, 0));

  SECTION("Round key is generated for all rounds from 0 to 3 inclusive")
    {
    for(size_t i = 0; i < 4; i++)
      REQUIRE_NOTHROW(get_round_key(key, i));
    }

  SECTION("Round key throws when round number is wrong")
    {
    REQUIRE_THROWS(get_round_key(key, 5));
    }

  SECTION("Round key is correctly generated for all rounds")
    {
    auto key_0 = get_round_key(key, 0);
    mblock_t ground_truth_key_0 = {0x4F, 0x59, 0x73, 0x36};
    REQUIRE(key_0 == ground_truth_key_0);

    auto key_1 = get_round_key(key, 1);
    mblock_t ground_truth_key_1 = {0x4E, 0x61, 0x39, 0x47};
    REQUIRE(key_1 == ground_truth_key_1);

    auto key_2 = get_round_key(key, 2);
    mblock_t ground_truth_key_2 = {0xB1, 0x9E, 0xC6, 0xB8};
    REQUIRE(key_2 == ground_truth_key_2);

    auto key_3 = get_round_key(key, 3);
    mblock_t ground_truth_key_3 = {0xB0, 0xA6, 0x8C, 0xC9};
    REQUIRE(key_3 == ground_truth_key_3);
    }

  }