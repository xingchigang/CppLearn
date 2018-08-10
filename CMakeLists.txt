cmake_minimum_required(VERSION 3.8)
#指定项目名称，一般和项目的文件夹名称对应：
project(CppLearn)
#头文件目录：
#INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x")
#源文件目录：
set(SOURCE_FILES main.cpp main.h LinkedList.cpp LinkedList.h)
#添加要编译的可执行文件：
add_executable(CppLearn ${SOURCE_FILES} )