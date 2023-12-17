cmake_minimum_required(VERSION 3.1...3.27)

project(
  RingFifoCpp
  VERSION 1.0
  LANGUAGES CXX)

add_library(RingFifoCpp)
target_sources(RingFifoCpp PRIVATE "ring_fifo.hpp")
set_target_properties(RingFifoCpp PROPERTIES LINKER_LANGUAGE CXX)

target_compile_features(RingFifoCpp PUBLIC cxx_std_17)