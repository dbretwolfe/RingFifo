cmake_minimum_required(VERSION 3.1...3.27)

project(
  RingFifoCProj
  VERSION 1.0
  LANGUAGES C)

add_library(RingFifoC STATIC)
target_sources(RingFifoC PUBLIC ring_fifo.c)
set_target_properties(RingFifoC PROPERTIES LINKER_LANGUAGE C)