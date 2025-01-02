#ifndef NEONCORE_VECTOR_OPS_H
#define NEONCORE_VECTOR_OPS_H

#include <cstddef> // For size_t

namespace neoncore {

// ==============================
// Vector Operations Interface
// ==============================

// Add two float arrays element-wise and store the result in a third array.
void add_float_arrays(const float *__restrict a, const float *__restrict b,
                      float *__restrict result, size_t size);

// Multiply two float arrays element-wise and store the result in a third array.
void mul_float_arrays(const float *__restrict a, const float *__restrict b,
                      float *__restrict result, size_t size);

// Subtract two float arrays element-wise and store the result in a third array.
void sub_float_arrays(const float *__restrict a, const float *__restrict b,
                      float *__restrict result, size_t size);

// Divide two float arrays element-wise and store the result in a third array.
void div_float_arrays(const float *__restrict a, const float *__restrict b,
                      float *__restrict result, size_t size);

// Dot product of two float arrays.
float dot_product_float_arrays(const float *__restrict a, const float *__restrict b, size_t size);

// Scale a float array by a scalar value.
void scale_float_array(const float *__restrict a, float scalar,
                       float *__restrict result, size_t size);

// Find the element-wise maximum between two float arrays.
void max_float_arrays(const float *__restrict a, const float *__restrict b,
                      float *__restrict result, size_t size);

// Find the element-wise minimum between two float arrays.
void min_float_arrays(const float *__restrict a, const float *__restrict b,
                      float *__restrict result, size_t size);

// Compute the length (magnitude) of a float array.
float vector_length(const float *__restrict a, size_t size);

// Normalize a float array.
void normalize_float_array(const float *__restrict a,
                           float *__restrict result, size_t size);

// Compute the element-wise square root of a float array.
void sqrt_float_array(const float *__restrict a,
                      float *__restrict result, size_t size);

// Compute the element-wise exponential of a float array.
void exp_float_array(const float *__restrict a,
                     float *__restrict result, size_t size);

// Compute the element-wise logarithm of a float array.
void log_float_array(const float *__restrict a,
                     float *__restrict result, size_t size);

} // namespace neoncore

#endif // NEONCORE_VECTOR_OPS_H
