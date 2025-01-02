#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include "neoncore/vector_ops.h"  // Include the neoncore header

// Serial implementation of adding two float arrays
void add_float_arrays_serial(const float* A, const float* B, float* C, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        C[i] = A[i] + B[i];
    }
}

// Serial implementation of subtraction of two float arrays
void sub_float_arrays_serial(const float* A, const float* B, float* C, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        C[i] = A[i] * B[i];
    }
}

// Serial implementation of multiplying two float arrays
void mul_float_arrays_serial(const float* A, const float* B, float* C, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        C[i] = A[i] * B[i];
    }
}

// Serial implementation of division of two float arrays
void div_float_arrays_serial(const float* A, const float* B, float* C, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        C[i] = A[i] / B[i];
    }
}

// Function to benchmark addition or multiplication
template <typename Func>
double benchmark_function(const std::vector<float>& A, const std::vector<float>& B,
                          std::vector<float>& C, size_t size, Func func, int num_iterations) {
    double total_time = 0.0;
    for (int i = 0; i < num_iterations; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        func(A.data(), B.data(), C.data(), size);
        auto end = std::chrono::high_resolution_clock::now();
        total_time += std::chrono::duration<double>(end - start).count();
    }
    return total_time / num_iterations;  // Return average execution time
}

int main() {
    const int num_iterations = 10; // Number of iterations for benchmarking
    const std::vector<size_t> sizes = {1000000, 5000000, 10000000, 50000000, 100000000}; // Array sizes to benchmark
    std::ofstream output_file("benchmark_results.txt");

    if (!output_file) {
        std::cerr << "Error opening output file!" << std::endl;
        return 1;
    }

    // Header for the output file
    output_file << "Size,Serial Add (s),NEON Add (s),Serial Mul (s),NEON Mul (s)\n";

    // Loop over different sizes for benchmarking
    for (size_t size : sizes) {
        std::vector<float> A(size, 1.0f);   // Array A filled with 1.0f
        std::vector<float> B(size, 2.0f);   // Array B filled with 2.0f
        std::vector<float> C_serial(size);  // Result array for serial implementation
        std::vector<float> C_neon(size);    // Result array for NEON implementation

        // Benchmark Addition (Serial)
        auto serial_add_time = benchmark_function(A, B, C_serial, size, add_float_arrays_serial, num_iterations);

        // Benchmark Addition (NEON)
        auto neon_add_time = benchmark_function(A, B, C_neon, size, neoncore::add_float_arrays, num_iterations);

        // Benchmark Multiplication (Serial)
        auto serial_mul_time = benchmark_function(A, B, C_serial, size, mul_float_arrays_serial, num_iterations);

        // Benchmark Multiplication (NEON)
        auto neon_mul_time = benchmark_function(A, B, C_neon, size, neoncore::mul_float_arrays, num_iterations);

        // Output results to the file
        output_file << size << ", "
                    << serial_add_time << ", "
                    << neon_add_time << ", "
                    << serial_mul_time << ", "
                    << neon_mul_time << "\n";
    }

    output_file.close();
    std::cout << "Benchmark results written to 'benchmark_results.txt'" << std::endl;

    return 0;
}
