# C++ Physics Engine for Orbital Simulation

This project is an educational physics engine written in modern C++ for simulating orbital mechanics and, eventually, the motion of bodies within the Solar System.

The current goal is to build the mathematical foundation, simulation architecture, and numerical integration system. After the core engine is stable and thoroughly tested, I plan to evaluate integration with established scientific tools and datasets such as REBOUND, JPL ephemeris data, and NASA's SPICE toolkit.

I took three introductory physics courses during my first two years of undergrad and have wanted to build a Solar System simulation ever since. This project is also an opportunity to strengthen my understanding of C++, numerical methods, software architecture, testing, and scientific computing.

## Current Progress

The current development phase focuses on the engine's core mathematical interface.

* Implementing and testing the `Vec3` class
* Writing unit tests with GoogleTest
* Using CMake to create a repeatable build and testing workflow
* Continuing the design of the core mathematical interface

  * `Quaternion` and matrix classes
  * Design decisions based on the needs of both simulation and rendering

## Near-Term Milestones

* Complete the core mathematical interface
* Finish testing the objects contained within the math layer
* Continue studying Ian Millington's *Game Physics Engine Development*
* Review additional physics engines and orbital-simulation libraries after the initial mechanics interface is complete
* Begin defining the data structures required for particles, bodies, forces, and system state

## Long-Term Milestones

Millington's force-generator architecture and numerical integration methods do not directly map onto the requirements of a Solar System simulation.

A gravitational N-body simulation requires each body's acceleration to depend on the positions and masses of the other bodies in the system. Because the system is coupled, the engine will need to evaluate the complete system state rather than process each body independently.

Planned long-term work includes:

* Designing an N-body gravitational force evaluator
* Implementing fourth-order Runge-Kutta integration
* Evaluating the coupled system at several intermediate states during each time step
* Testing conservation of momentum, angular momentum, and total energy
* Comparing the simulation against known orbital solutions
* Evaluating future integration with REBOUND, JPL ephemeris data, and SPICE

## Tools

* MSYS2 UCRT64 environment
* GCC `g++` 16.1.0
* Ninja 1.13.2
* CMake 4.3.3

  * GoogleTest managed through CMake `FetchContent`
  * Minimum required CMake version: 3.20

## Testing and Documentation Assistance

ChatGPT was used as a learning and development aid during the setup of the testing infrastructure and project documentation.

Its assistance included:

* Explaining GoogleTest concepts and command-line usage
* Helping design initial `Vec3` test cases
* Explaining the CMake build and test configuration
* Assisting with README structure, wording, and clarity

All generated code, tests, documentation, and design suggestions are reviewed, modified, and validated before being incorporated into the project.

## Build Instructions

From the repository root:

```bash
cmake -S . -B build -G Ninja
cmake --build build
```

## Running the Tests

Run the complete test suite through CTest:

```bash
ctest --test-dir build --output-on-failure
```

Run the GoogleTest executable directly:

```bash
./build/math_core_tests.exe
```

## Sources

Books, documentation, articles, and external technical references used during development are recorded in [`sources.md`](sources.md).
