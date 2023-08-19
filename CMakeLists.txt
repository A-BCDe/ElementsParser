cmake_minimum_required(VERSION 3.22)
project(ElementsParser)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(3rd/PEGTL)

add_library(ElementsParser INTERFACE)
target_include_directories(ElementsParser
    INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(ElementsParser INTERFACE taocpp::pegtl)

add_subdirectory(test)