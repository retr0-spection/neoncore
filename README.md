# NeonCore - A High-Performance Math Library for ARM

**NeonCore** is a highly optimized C++ math library designed to leverage **ARM's NEON** SIMD (Single Instruction, Multiple Data) instructions for high-performance computations. This library is built for developers who want to harness the power of ARM processors, particularly for tasks such as linear algebra, vector operations, and other computationally intensive math operations.

## Features

- **Optimized for ARM**: Uses ARM NEON SIMD instructions for improved performance on ARM-based processors.
- **Minimal Overhead**: A lightweight and efficient library with a focus on performance, using ARM-specific optimizations for vector operations.


## Table of Contents

- [Installation](#installation)
- [Usage](#usage)

## Installation

To install **NeonCore**, simply clone the repository and build it using CMake. You can also set up the project in your own build environment with minimal dependencies.

### Dependencies

- **CMake** (for building the project)
- **Google Test** (for running tests)

### Steps to Install:

1. Clone the repository:

   ```bash
   git clone https://github.com/retr0-spection/neoncore.git
   cd neoncore
   ```
2. Create a build directory:
  ```bash
  mkdir build
  cd build
  ```
3. Configure the project using CMake:
  ```bash
  cmake ..
  ```
4.	Build the project:
  ```bash
  make
  ```
## Usage
  ```cpp
  #include "neoncore/neoncore.h"

  int main() {
      float array1[] = {1.0f, 2.0f, 3.0f, 4.0f};
      float array2[] = {5.0f, 6.0f, 7.0f, 8.0f};
      float result[4];

      NeonCore::add_float_arrays(array1, array2, result, 4);

      // Output: [6.0, 8.0, 10.0, 12.0]
      for (int i = 0; i < 4; i++) {
          std::cout << result[i] << " ";
      }

      return 0;
  }
  ```
