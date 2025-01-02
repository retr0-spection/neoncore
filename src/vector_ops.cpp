#include "neoncore/vector_ops.h"
#include <arm_neon.h> // NEON intrinsics for ARM SIMD
#include <cstddef>    // For size_t
#include <stdexcept>  // For std::runtime_error
#include <limits>     // For std::numeric_limits

namespace neoncore {

// ==============================
// Implementation of vector operations
// ==============================

// Add two float arrays element-wise and store the result in a third array.
// This function processes 4 elements at a time using NEON SIMD instructions.
void add_float_arrays(const float *__restrict a, const float *__restrict b,
                      float *__restrict result, size_t size) {
  size_t i = 0;
  // // Process 4 elements at a time
  for (; i + 4 <= size; i += 4) {
    // Load 4 floats from each array into NEON registers
    float32x4_t va = vld1q_f32(&a[i]); // Load from 'a'
    float32x4_t vb = vld1q_f32(&b[i]); // Load from 'b'

    // Add the two vectors (element-wise)
    float32x4_t vresult = vaddq_f32(va, vb);

    // Store the result back into the 'result' array
    vst1q_f32(&result[i], vresult);
  }

  // Handle any remaining elements (less than 4)
  for (; i < size; ++i) {
    result[i] = a[i] + b[i];
  }
}

void mul_float_arrays(const float *__restrict a, const float *__restrict b,
                      float *__restrict result, size_t size) {
  size_t i = 0;

  for (; i + 4 <= size; i += 4) {
    // Load 4 floats from each array into NEON registers
    float32x4_t va = vld1q_f32(&a[i]); // Load from 'a'
    float32x4_t vb = vld1q_f32(&b[i]); // Load from 'b'

    // Multiply the two vectors (element-wise)
    float32x4_t vresult = vmulq_f32(va, vb);

    // Store the result back into the 'result' array
    vst1q_f32(&result[i], vresult);
  }

  // Handle any remaining elements (less than 4)
  for (; i < size; ++i) {
    result[i] = a[i] * b[i];
  }
}

void sub_float_arrays(const float *__restrict a, const float *__restrict b,
                      float *__restrict result, size_t size) {
  size_t i = 0;
  // Process 4 elements at a time
  for (; i + 4 <= size; i += 4) {
    // Load 4 floats from each array into NEON registers
    //
    float32x4_t va = vld1q_f32(&a[i]); // Load from 'a'
    float32x4_t vb = vld1q_f32(&b[i]); // Load from 'b'
    // Add the two vectors (element-wise)
    float32x4_t vresult = vsubq_f32(va, vb);

    // Store the result back into the 'result' array
    vst1q_f32(&result[i], vresult);
  }
}

void div_float_arrays(const float *__restrict a, const float *__restrict b,
                      float *__restrict result, size_t size) {
  size_t i = 0;
  for (; i + 4 <= size; i += 4) {
      // Load 4 floats from each array into NEON registers
      float32x4_t va = vld1q_f32(&a[i]);
      float32x4_t vb = vld1q_f32(&b[i]);

      // Check for zero division
      uint32x4_t vz = vceqq_f32(vb, vdupq_n_f32(0.0f));
      if (vgetq_lane_u32(vz, 0) || vgetq_lane_u32(vz, 1) ||
          vgetq_lane_u32(vz, 2) || vgetq_lane_u32(vz, 3)) {
          throw std::runtime_error("Division by zero encountered in array 'b'.");
      }

      // Compute accurate reciprocal using Newton-Raphson refinement
      float32x4_t vrecip = vrecpeq_f32(vb);
      // First refinement step
      float32x4_t vs = vrecpsq_f32(vb, vrecip);
      vrecip = vmulq_f32(vs, vrecip);
      // Second refinement step for better accuracy
      vs = vrecpsq_f32(vb, vrecip);
      vrecip = vmulq_f32(vs, vrecip);

      // Multiply a by refined reciprocal of b
      float32x4_t vresult = vmulq_f32(va, vrecip);
      vst1q_f32(&result[i], vresult);
  }

  // Handle remaining elements
  for (; i < size; ++i) {
      if (b[i] == 0.0f) {
          throw std::runtime_error("Division by zero encountered in array 'b'.");
      }
      result[i] = a[i] / b[i];
  }

}

} // namespace neoncore
