cmake_minimum_required(VERSION 3.1...3.27)

project(
  RingFifoCppProj
  VERSION 1.0
  LANGUAGES CXX)

add_library(RingFifoCpp INTERFACE)
target_include_directories(RingFifoCpp INTERFACE ./)
set_target_properties(RingFifoCpp PROPERTIES LINKER_LANGUAGE CXX)