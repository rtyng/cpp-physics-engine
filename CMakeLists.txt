cmake_minimum_required(VERSION 3.20)

project(
    cpp_physics_engine
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---------------------------------------------------------------------------
# Math library
# ---------------------------------------------------------------------------

add_library(math_core INTERFACE)

target_include_directories(
    math_core
    INTERFACE
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_options(
    math_core
    INTERFACE
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -Wshadow
)

# ---------------------------------------------------------------------------
# Simulation executable
# ---------------------------------------------------------------------------

add_executable(
    physics_sim
    src/main.cpp
)

target_link_libraries(
    physics_sim
    PRIVATE
        math_core
)

# ---------------------------------------------------------------------------
# Testing
# ---------------------------------------------------------------------------

include(CTest)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)

    add_executable(
        math_core_tests
        tests/test_vec3.cpp
    )

    target_link_libraries(
        math_core_tests
        PRIVATE
            math_core
            GTest::gtest_main
    )

    include(GoogleTest)

    gtest_discover_tests(math_core_tests)
endif()