cmake_minimum_required(VERSION 3.4)
project(DigSig)

set(CMAKE_CXX_STANDARD 11) # adds -std=c++11
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES src/misty.h src/misty.cpp src/common.h src/bitwise.h src/bitwise.cpp src/hash.cpp src/hash.h)
set(TEST_FILES tests/test.cpp tests/test_misty.cpp tests/test_hash.cpp)

add_library(DigSig_Shared SHARED ${SOURCE_FILES})
add_library(DigSig_Static STATIC ${SOURCE_FILES})

add_executable(DigSig_Test ${TEST_FILES})
target_link_libraries(DigSig_Test DigSig_Static)

ADD_CUSTOM_COMMAND(
        TARGET DigSig_Test POST_BUILD
        COMMAND cmake -E copy "${CMAKE_SOURCE_DIR}/tests/random_data.txt"
                              "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"

        COMMENT "copying input data for test"
        )