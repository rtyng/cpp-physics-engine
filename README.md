# C++ Lab for Benchmarking Numerical Integration Techniques

A platform built in C++ for implementing, comparing, validating, and visualizing numerical integration methods for orbital dynamics.

For now, I deleted the build folder and moved everything into /archive. I am going to be coming back to this later on after practicing building programs in python for a couple months. Doesn't make much sense to waste effort on C++ when I need to focus on the fundamentals. Easier to do that in a language that I have much more experience in. 

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
