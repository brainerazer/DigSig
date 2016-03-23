//
// Created by Bohdan Rybak on 22.03.2016.
//
#include "catch.hpp"

#include "../src/common.h"
#include "../src/misty.h"

TEST_CASE("Round key is generated", "[misty]")
  {
  block_t key = 0x4E6139474F597336;

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
    mblock_t ground_truth_key_0 = 0x4F597336;
    REQUIRE(key_0 == ground_truth_key_0);

    auto key_1 = get_round_key(key, 1);
    mblock_t ground_truth_key_1 = 0x4E613947;
    REQUIRE(key_1 == ground_truth_key_1);

    auto key_2 = get_round_key(key, 2);
    mblock_t ground_truth_key_2 = 0xB19EC6B8;
    REQUIRE(key_2 == ground_truth_key_2);

    auto key_3 = get_round_key(key, 3);
    mblock_t ground_truth_key_3 = 0xB0A68CC9;
    REQUIRE(key_3 == ground_truth_key_3);
    }

  }