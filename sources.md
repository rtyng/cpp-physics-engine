# Sources and Technical References

This document records the books, papers, software projects, datasets, and technical documentation consulted during development.

The references are organized by their role in the project. Descriptions under each citation explain how the source was used in the platforma's design or implementation.

## Orbital Mechanics

### [1] Howard D. Curtis, *Orbital Mechanics for Engineering Students*, 4th ed. Oxford, U.K.: Butterworth-Heinemann, 2020.

**Project use:** Two-body motion, orbital elements, state vectors, propagation methods, and validation of orbital calculations.

## Numerical Methods and Computational Physics

### [2] Nicholas J. Giordano and Hisao Nakanishi, *Computational Physics*, 2nd ed. Upper Saddle River, NJ, USA: Pearson Prentice Hall, 2006.

**Project use:** Numerical simulation methodology, ordinary differential equations, computational modeling, error analysis, and validation of physical simulations.

**Supplementary materials:** [Purdue Computational Physics resources](https://www.physics.purdue.edu/~hisao/book/)


## Software Development and Testing

### [3] Google, “GoogleTest Documentation.”

* [GoogleTest primer](https://google.github.io/googletest/primer.html)
* [Assertions reference](https://google.github.io/googletest/reference/assertions.html)
* [CMake quickstart](https://google.github.io/googletest/quickstart-cmake.html)

Accessed: July 2026.

**Project use:** Unit-test organization, assertions, floating-point comparisons, test fixtures, test discovery, and integration with CMake and CTest.

### [4] Kitware, “CMake Documentation.”

* [CMake documentation](https://cmake.org/documentation/)
* [GoogleTest CMake module](https://cmake.org/cmake/help/latest/module/GoogleTest.html)
* [FetchContent module](https://cmake.org/cmake/help/latest/module/FetchContent.html)

Accessed: July 2026.

**Project use:** Target-based build configuration, interface libraries, dependency management, compiler options, GoogleTest integration, and CTest registration.

## AI-Assisted Development

ChatGPT was used as a learning and development aid for:

* Explaining C++ and CMake concepts
* Reviewing project documentation
* Generating initial GoogleTest examples
* Suggesting test cases and edge cases
* Discussing software architecture and numerical-method design

All AI-generated suggestions are reviewed, modified, compiled, tested, and validated before being incorporated into the project. ChatGPT is not treated as an authoritative technical source; primary documentation, textbooks, papers, and experimental results are used to verify technical claims.

