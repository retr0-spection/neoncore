cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(NeonCore VERSION 1.0 LANGUAGES CXX)

# Enable C++17 (or higher)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the build type
set(CMAKE_BUILD_TYPE Release)

# Add the include directory where your headers are located
include_directories(${PROJECT_SOURCE_DIR}/include)  # Include the include directory

# Add the main NeonCore library (neoncore)
add_library(neoncore SHARED
    src/vector_ops.cpp
    # Include additional source files here as your library grows
)

# Install library and headers
#install(TARGETS neoncore DESTINATION /usr/local/lib)
#install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION /usr/local/include)


#set(CMAKE_INSTALL_RPATH "/usr/local/lib")

# -----------------------------
# Find GoogleTest (using Homebrew)
# -----------------------------
find_package(GTest REQUIRED)

# -----------------------------
# Create the test executable
# -----------------------------
add_executable(test_neoncore
    tests/test_neoncore.cpp  # Ensure this file exists or adjust the path accordingly
)



# Link GoogleTest and NeonCore library to the test executable
target_link_libraries(test_neoncore
    neoncore      # Link the NeonCore library
    GTest::GTest  # Link the GoogleTest library
    GTest::Main   # Link the GoogleTest main function
)

# -----------------------------
# Enable testing and run tests
# -----------------------------
enable_testing()
add_test(NAME NeonCoreTest COMMAND test_neoncore)

# -----------------------------
# Add Benchmark Executable (New Addition)
# -----------------------------
# Add the benchmark executable for the vector_benchmark.cpp
add_executable(vector_benchmark
    benchmarks/vector_benchmark.cpp
)

# Link NeonCore to the benchmark executable
target_link_libraries(vector_benchmark
    neoncore  # Link the NeonCore library
)
