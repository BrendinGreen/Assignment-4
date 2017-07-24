cmake_minimum_required(VERSION 3.7)
project(Assignment_4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp WordPair.cpp ElementAlreadyExistsInBSTException.cpp ElementDoesNotExistInBSTException.cpp BSTNode.h BST.h)
add_executable(Assignment_4 ${SOURCE_FILES})