# C++ Lab for Benchmarking Numerical Integration Techniques

A platform built in C++ for implementing, comparing, validating, and visualizing numerical integration methods for orbital dynamics.


## Numerical Integration methods 

- Explicit Euler
- Semi-implicit Euler
- RK4
- Leapfrog
- REBOUND IAS15
- REBOUND WHFast

## Metrics 

- Runtime
- Final position error
- Orbital period error
- Energy drift
- Angular-momentum drift

## Tools

* MSYS2 UCRT64 environment
* GCC `g++` 16.1.0
* Ninja 1.13.2
* CMake 4.3.3

  * GoogleTest managed through CMake `FetchContent`
  * Minimum required CMake version: 3.20



## Sources

Books, documentation, articles, and external technical references used during development are recorded in [`sources.md`](sources.md).
