cmake_minimum_required(VERSION 3.4)
project(DigSig)

set(CMAKE_CXX_STANDARD 11) # adds -std=c++11
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES src/misty.h src/misty.cpp src/common.h src/bitwise.h src/bitwise.cpp)
set(TEST_FILES tests/test.cpp tests/test_misty.cpp)

add_library(DigSig_Lib ${SOURCE_FILES})

add_executable(DigSig main.cpp)
target_link_libraries(DigSig DigSig_Lib)

add_executable(DigSig_Test ${TEST_FILES})
target_link_libraries(DigSig_Test DigSig_Lib)