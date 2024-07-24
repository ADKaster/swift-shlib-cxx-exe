
add_library(shlib SHARED
  Color.cpp
  Color.swift
)

target_include_directories(shlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(shlib PUBLIC "SHELL:$<$<COMPILE_LANGUAGE:Swift>:-Xcc -std=c++23 -cxx-interoperability-mode=default>")
target_compile_features(shlib PUBLIC cxx_std_23)
set_target_properties(shlib PROPERTIES Swift_MODULE_NAME "SwiftShlib")

_swift_generate_cxx_header(shlib "shlib-Swift.h"
    SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}
)
