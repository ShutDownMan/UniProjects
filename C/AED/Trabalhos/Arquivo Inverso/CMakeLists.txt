cmake_minimum_required(VERSION 3.11)
project(Arquivo_Inverso C)

set(CMAKE_C_STANDARD 99)

add_executable(Arquivo_Inverso main.c BTree.c BTree.h Queue.c Queue.h InvertionFileManipulation.c InvertionFileManipulation.h Registy.c Registy.h)