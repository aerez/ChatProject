cmake_minimum_required(VERSION 3.14)
project(TcpChatClient)

set(CMAKE_CXX_STANDARD 14)

add_executable(TcpChatClient main.cpp TcpClient.h TcpClient.cpp)