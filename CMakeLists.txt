cmake_minimum_required(VERSION 3.17)
project(transaction_list_multifile)

set(CMAKE_CXX_STANDARD 14)

add_executable(transaction_list_multifile main.cpp transaction.cpp transaction.h)