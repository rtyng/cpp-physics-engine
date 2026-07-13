# C++ Lab for Benchmarking Numerical Integration Techniques

A C++ platform for implementing, comparing, validating, and visualizing numerical integration methods for orbital dynamics.


## Near-Term Milestones

- Define the platform's experiment workflow
- Select the first simulation libraries and integrators
- Build a REBOUND integration layer
- Create shared configuration and result formats
- Add command-line experiment execution
- Export results to CSV or JSON

## Long-Term Milestones

- Support multiple orbital-simulation backends
- Compare accuracy, stability, and runtime across integrators
- Add JPL Horizons and SPICE data support
- Provide optional raylib visualization
- Add reproducible benchmark scenarios
- Package the platform for use on other systems

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
build/math_core_tests.exe
```

## Sources

Books, documentation, articles, and external technical references used during development are recorded in [`sources.md`](sources.md).
