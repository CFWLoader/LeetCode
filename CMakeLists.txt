cmake_minimum_required(VERSION 3.1)
project(ChatRoom)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lpthread")

set(SOURCE_FILES main.cpp)
add_executable(ChatRoom ${SOURCE_FILES} chatserver/ChatServer.cpp chatserver/ChatServer.h utils/Socket.cpp utils/Socket.h utils/ServerSocket.cpp utils/ServerSocket.h)