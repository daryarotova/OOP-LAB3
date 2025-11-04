cmake_minimum_required(VERSION 3.10)

project(Lab3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(lab3
    main.cpp
    src/pentagon.cpp
    src/hexagon.cpp
    src/octagon.cpp
    src/figure_array.cpp
)

find_package(GTest REQUIRED)

add_executable(tests_lab3
    tests/tests.cpp
    src/pentagon.cpp
    src/hexagon.cpp
    src/octagon.cpp
    src/figure_array.cpp
)

target_link_libraries(tests_lab3 GTest::gtest GTest::gtest_main)

enable_testing()
add_test(NAME lab3_tests COMMAND tests_lab3)
