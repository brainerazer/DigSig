//
// Created by Bohdan Rybak on 22.03.2016.
//
#include "catch.hpp"

#include "../src/common.h"
#include "../src/bitwise.h"
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

TEST_CASE("Encryption is performed", "[misty]")
  {
  SECTION("Rounds give correct outputs")
    {
    mblock_t L = 0xF4AB023A; // L0
    mblock_t R = 0xD6F9A6E3; // R0

    mblock_t round_keys[] = {0x9DC15B68, 0x98CF9F97, 0x67306068, 0x623EA497};
    mblock_t ground_truth_L[] = {0x1E2CB45A, 0x75FE1E52, 0xFCFA6881, 0xA26EB696};

    for(size_t i = 0; i < 4; i++)
      {
      mblock_t new_L = perform_round(L, R, round_keys[i]);

      REQUIRE(new_L == ground_truth_L[i]);
      R = L;
      L = new_L;
      }
    }

  SECTION("Encryption is done correctly")
    {
    block_t message = 0xA26EB696FCFA6881;
    block_t key = 0xE31680C5B1B343F9;
    block_t ground_truth_encrypted = 0xE7BD867A86E36FF6;

    block_t encrypted = encrypt(message, key);
    REQUIRE(encrypted == ground_truth_encrypted);
    }
  }