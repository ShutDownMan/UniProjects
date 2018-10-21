cmake_minimum_required(VERSION 3.11)
project(BTree C)

set(CMAKE_C_STANDARD 99)

add_executable(BTree main.c BTree.h BTree.c Queue.c Queue.h)