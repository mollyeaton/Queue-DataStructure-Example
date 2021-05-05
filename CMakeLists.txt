cmake_minimum_required(VERSION 3.15)
project(Assignment03 C)

set(CMAKE_C_STANDARD 99)

add_executable(Assignment03 pqueue.maeaton.c pqueue.maeaton.h pqueue-tests.c)
add_executable(Double pqueue-double.maeaton.c pqueue.maeaton.h pqueue-tests.c)