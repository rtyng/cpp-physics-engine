# C++ Physics Engine for Orbital Simulation

This project is an educational physics engine written in modern C++ for simulating orbital mechanics and, eventually, the motion of bodies within the Solar System.

The current goal is to build the mathematical foundation, simulation architecture, and numerical integration system from first principles. After the core engine is stable and thoroughly tested, I plan to evaluate integration with established scientific tools and datasets such as REBOUND, JPL ephemeris data, and NASA's SPICE toolkit.

I took three introductory physics courses during my first two years of undergraduate study and have wanted to build a Solar System simulation ever since. This project is also an opportunity to strengthen my understanding of C++, numerical methods, software architecture, testing, and scientific computing.

## Current Progress

The current development phase focuses on the engine's core math interface.

- Testing 'Vec3' class before and after implementation
- Writing unit tests with GoogleTest
- Using CMake to create a build and test workflow
- Continue designing core math interface 
    - 'Quaternion' and 'Mat' classes
    - Design decisions based on simulation and rendering

## Current Architecture

The mathematical core is currently implemented as a header-only CMake interface library.

cpp-physics-engine/
├── include/
│   └── math-core.hpp
├── src/
│   └── main.cpp
├── tests/
│   └── test_vec3.cpp
├── CMakeLists.txt
├── README.md
└── sources.md

## Near-Future Milestones

- Finish core math interface and finish testing the objects within it
- Continue studying Millington's Game Physics Engine Development
- Look into other engines for planetary motion after building interface for the laws of motion, and the particle physics

## Longer-Term Milestones

- Millington's force generator and numerical integration methods do not directly map over to a simulation of the solar system
- Gravitational N-Body simulation requires each body's acceleration to depend on the position and masses of other bodies in the system
- RK4 will need to be implemented in order to evauluate the system at several states during each time-step


## Tools

- MSYS2 UCRT64 environment
- GCC 'g++' 16.1.0
- Ninja 1.13.2
- CMake 4.3.3
    - GoogleTest managed through CMake 'FetchContent'
    - CMake minimum required version: 3.20

## Build Instructions

From the repository root:

cmake -S . -B build -G Ninja
cmake --build build
ctest --test-dir build --output-on-failure

## Running the Tests

Run the complete test suite through CTest:

ctest --test-dir build --output-on-failure

Run the GoogleTest executable directly:

./build/math_core_tests.exe

