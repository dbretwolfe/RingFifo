cmake_minimum_required(VERSION 3.1...3.27)

project(
  RingFifoC
  VERSION 1.0
  LANGUAGES C)

add_library(RingFifoC)
target_sources(RingFifoC PRIVATE "ring_fifo.h" "ring_fifo.c")
set_target_properties(RingFifoC PROPERTIES LINKER_LANGUAGE C)