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
  block_t prev_hash = 0x75B557A7DD5B3D84;
  block_t message = 0x52596A697439364E;
  block_t ground_truth_hash = 0xA7EA999A73039C89;

  block_t result = hash_round(prev_hash, message);
  REQUIRE(result == ground_truth_hash);
  }

TEST_CASE("Test hash overall", "[hash]")
  {

  }