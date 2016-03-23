//
// Created by Bohdan Rybak on 24.03.2016.
//

#include "catch.hpp"

#include "../src/common.h"
#include "../src/hash.h"

TEST_CASE("Test message padding", "[hash]")
  {

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