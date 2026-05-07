cmake_minimum_required(VERSION 3.20)

project(TwoSumProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(TWOSUM_BUILD_TESTS "Build unit tests" ON)

add_library(twosum
    src/twosum.cpp
)

target_include_directories(twosum
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(twosum PUBLIC cxx_std_20)

add_executable(TwoSumApp
    src/main.cpp
)

target_link_libraries(TwoSumApp PRIVATE twosum)

add_executable(TwoSumBenchmark
    src/benchmark.cpp
)

target_link_libraries(TwoSumBenchmark PRIVATE twosum)

# Tests
if(TWOSUM_BUILD_TESTS)
    include(CTest)
    enable_testing()

    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.14.0
    )

    # For Windows/MSVC: keep consistent runtime settings.
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)

    add_executable(TwoSumTest
        tests/test_twosum.cpp
    )
    target_link_libraries(TwoSumTest PRIVATE twosum GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(TwoSumTest)
endif()
