cmake_minimum_required(VERSION 3.20)

project(
    cpp_physics_engine
    VERSION 0.1.0
    LANGUAGES CXX
)

# Use a modern C++ language standard throughout the project, set c++ standard, and disable compiler-specific langauge extensions
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---------------------------------------------------------------------------
# Engine library
# ---------------------------------------------------------------------------

# Define core math interface as a target
# math-core.hpp is currently header-only, so INTERFACE is appropriate.
add_library(math-core INTERFACE)

# Give other directories access to header directory
target_include_directories(
    math-core
    INTERFACE
        ${PROJECT_SOURCE_DIR}/include
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
        physics_core
)

# ---------------------------------------------------------------------------
# Compiler warnings
# ---------------------------------------------------------------------------

# -Wconversion for warnings about implicit conversions to avoid accidental precision loss
# -Wshadow for catching subtle declaration mistakes. Ex: a constructor mass parameter shadowing a member named mass
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(
        physics_sim
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Wconversion
            -Wshadow
    )
endif()

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

    # Primarily relevant when using Microsoft's compiler, but harmless here.
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)

    add_executable(
        math_core_tests
        tests/vec3_tests.cpp
    )

    target_link_libraries(
        math_core_tests
        PRIVATE
            physics_core
            GTest::gtest_main
    )

    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(
            math_core_tests
            PRIVATE
                -Wall
                -Wextra
                -Wpedantic
                -Wconversion
                -Wshadow
        )
    endif()

    include(GoogleTest)

    gtest_discover_tests(math_core_tests)
endif()