cmake_minimum_required(VERSION 3.1...3.27)

project(
  RingFifoCppTestProj
  VERSION 1.0
  LANGUAGES C CXX)

add_executable(RingFifoCppTest)
target_sources(RingFifoCppTest PUBLIC 
  fifo_test.cpp
)

target_include_directories(RingFifoCppTest PUBLIC ./ ../../ring_fifo_cpp/)
target_link_libraries(RingFifoCppTest PUBLIC RingFifoCpp PRIVATE GTest::gtest_main)
target_compile_features(RingFifoCppTest PUBLIC cxx_std_20)

include(GoogleTest)
gtest_discover_tests(RingFifoCppTest)
