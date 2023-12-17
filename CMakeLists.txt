cmake_minimum_required(VERSION 3.1...3.27)

project(
  RingFifo
  VERSION 1.0)
  
add_subdirectory(ring_fifo_c)
add_subdirectory(ring_fifo_cpp)
add_subdirectory(tests/ring_fifo_c)
#add_subdirectory(tests/ring_fifo_cpp)