cmake_minimum_required(VERSION 3.16)
project(urm)

set(CMAKE_CXX_STANDARD 17)

add_executable(urm
               src/main.cpp
               src/urm.cpp
               src/storage.cpp
               src/storage_impl.hpp
               src/decoder.cpp
               src/instruction.cpp)
