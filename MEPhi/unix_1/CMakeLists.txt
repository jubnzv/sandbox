cmake_minimum_required(VERSION 2.8)

project("Labs")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

enable_language(C)

add_subdirectory(src)
