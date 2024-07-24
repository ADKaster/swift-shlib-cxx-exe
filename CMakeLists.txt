cmake_minimum_required(VERSION 3.30)

project(test LANGUAGES CXX Swift)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT APPLE)
  set(CMAKE_LINKER_TYPE LLD)
  add_link_options(LINKER:--no-allow-shlib-undefined)
  add_link_options(LINKER:--no-undefined)
endif()

include(cmake/InitializeSwift.cmake)
include(cmake/GenerateSwiftHeader.cmake)

add_subdirectory(shlib)
add_subdirectory(exe)
