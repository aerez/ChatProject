cmake_minimum_required(VERSION 3.14)
project(TcpChatServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(TcpChatServer main.cpp TcpServer.h TcpServer.cpp Client.h Client.cpp)