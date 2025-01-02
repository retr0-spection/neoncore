#include "neoncore/vector_ops.h" // Include the main NeonCore header
#include <gtest/gtest.h>
#include <vector>

// Test for adding two float vectors
TEST(NeonCoreTest, AddFloatVectors) {
  const size_t size = 8;
  std::vector<float> a = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f};
  std::vector<float> b = {8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f};
  std::vector<float> result(size, 0.0f);

  // Call the add_float_arrays function
  neoncore::add_float_arrays(a.data(), b.data(), result.data(), size);

  // Expected result after adding the two arrays element-wise
  std::vector<float> expected = {9.0f, 9.0f, 9.0f, 9.0f,
                                 9.0f, 9.0f, 9.0f, 9.0f};

  // Verify the results
  for (size_t i = 0; i < size; ++i) {
    EXPECT_NEAR(result[i], expected[i],
                1e-6f); // Floating-point comparison with tolerance
  }
}

// Test for adding two arrays of different sizes (edge case)
TEST(NeonCoreTest, AddFloatArraysDifferentSizes) {
    const size_t size = 5;
    float a[size] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    float b[size] = {5.0f, 4.0f, 3.0f, 2.0f, 1.0f};
    float result[size] = {0.0f};

    // Call the add_float_arrays function
    neoncore::add_float_arrays(a, b, result, size);

    // Expected result after adding the two arrays element-wise
    float expected[size] = {6.0f, 6.0f, 6.0f, 6.0f, 6.0f};

    // Compare the result with the expected values
    for (size_t i = 0; i < size; ++i) {
        EXPECT_NEAR(result[i], expected[i], 1e-6f);  // Floating-point comparison with tolerance
    }
}

// Test for the case when one of the arrays is all zeros
TEST(NeonCoreTest, AddFloatArraysZeroArray) {
    const size_t size = 4;
    float a[size] = {0.0f, 0.0f, 0.0f, 0.0f};
    float b[size] = {1.0f, 2.0f, 3.0f, 4.0f};
    float result[size] = {0.0f};

    // Call the add_float_arrays function
    neoncore::add_float_arrays(a, b, result, size);

    // Expected result (b array itself, since a is all zeros)
    float expected[size] = {1.0f, 2.0f, 3.0f, 4.0f};

    // Compare the result with the expected values
    for (size_t i = 0; i < size; ++i) {
        EXPECT_NEAR(result[i], expected[i], 1e-6f);  // Floating-point comparison with tolerance
    }
}

// Test for multiplying two float vectors
TEST(NeonCoreTest, MulFloatVectors) {
  const size_t size = 8;
  std::vector<float> a = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f};
  std::vector<float> b = {8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f};
  std::vector<float> result(size, 0.0f);

  // Call the mul_float_arrays function
  neoncore::mul_float_arrays(a.data(), b.data(), result.data(), size);

  // Expected result after multiplying the two arrays element-wise
  std::vector<float> expected = {8.0f,  14.0f, 18.0f, 20.0f,
                                 20.0f, 18.0f, 14.0f, 8.0f};

  // Verify the results
  for (size_t i = 0; i < size; ++i) {
    EXPECT_NEAR(result[i], expected[i],
                1e-6f); // Floating-point comparison with tolerance
  }
}

// Test for multiplying two vectors of different sizes (edge case)
TEST(NeonCoreTest, MulFloatVectorsDifferentSizes) {
  const size_t size = 5;
  std::vector<float> a = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
  std::vector<float> b = {5.0f, 4.0f, 3.0f, 2.0f, 1.0f};
  std::vector<float> result(size, 0.0f);

  // Call the mul_float_arrays function
  neoncore::mul_float_arrays(a.data(), b.data(), result.data(), size);

  // Expected result after multiplying the two arrays element-wise
  std::vector<float> expected = {5.0f, 8.0f, 9.0f, 8.0f, 5.0f};

  // Verify the results
  for (size_t i = 0; i < size; ++i) {
    EXPECT_NEAR(result[i], expected[i],
                1e-6f); // Floating-point comparison with tolerance
  }
}

// Test for multiplying with one vector being all zeros
TEST(NeonCoreTest, MulFloatVectorsZeroVector) {
  const size_t size = 4;
  std::vector<float> a = {0.0f, 0.0f, 0.0f, 0.0f};
  std::vector<float> b = {1.0f, 2.0f, 3.0f, 4.0f};
  std::vector<float> result(size, 0.0f);

  // Call the mul_float_arrays function
  neoncore::mul_float_arrays(a.data(), b.data(), result.data(), size);

  // Expected result (all zeros)
  std::vector<float> expected = {0.0f, 0.0f, 0.0f, 0.0f};

  // Verify the results
  for (size_t i = 0; i < size; ++i) {
    EXPECT_NEAR(result[i], expected[i],
                1e-6f); // Floating-point comparison with tolerance
  }
}

// Test for subtracting two float vectors
TEST(NeonCoreTest, SubFloatVectors){
    const size_t size = 4;
    std::vector<float> a = {1.0f, 8.0f, 3.0f, 10.0f};
    std::vector<float> b = {8.0f, 7.0f, 6.0f, 5.0f};
    std::vector<float> result(size, 0.0f);

    // Call the sub_float_arrays function
    neoncore::sub_float_arrays(a.data(), b.data(), result.data(), size);

    // Expected result (all zeros)
    std::vector<float> expected = {-7.0f, 1.0f, -3.0f, 5.0f};

    // Verify the results
    for (size_t i = 0; i < size; ++i) {
      EXPECT_NEAR(result[i], expected[i],
                  1e-6f); // Floating-point comparison with tolerance
    }
}

// ==========================
// Division Tests
// ==========================
TEST(NeonCoreTest, DivFloatVectors) {
    const size_t size = 4;
    std::vector<float> a = {4.0f, 8.0f, 12.0f, 16.0f};
    std::vector<float> b = {2.0f, 4.0f, 6.0f, 8.0f};
    std::vector<float> result(size, 0.0f);

    // Call the div_float_arrays function
    neoncore::div_float_arrays(a.data(), b.data(), result.data(), size);

    // Expected result after division
    std::vector<float> expected = {2.0f, 2.0f, 2.0f, 2.0f};

    // Verify the results
    for (size_t i = 0; i < size; ++i) {
        std::cout << result[i] <<std::endl;
        EXPECT_NEAR(result[i], expected[i],
                    1e-6f); // Floating-point comparison with tolerance
    }
}


// Test for dividing with one vector being all zeros
TEST(NeonCoreTest, DivFloatVectorsZeroVector) {
    const size_t size = 4;
    std::vector<float> a = {0.0f, 0.0f, 0.0f, 0.0f};
    std::vector<float> b = {1.0f, 2.0f, 3.0f, 4.0f};
    std::vector<float> result(size, 0.0f);

    // Call the div_float_arrays function
    neoncore::div_float_arrays(a.data(), b.data(), result.data(), size);

    // Expected result (all zeros, since the numerator is zero)
    std::vector<float> expected = {0.0f, 0.0f, 0.0f, 0.0f};

    // Verify the results
    for (size_t i = 0; i < size; ++i) {
        EXPECT_NEAR(result[i], expected[i],
                    1e-6f); // Floating-point comparison with tolerance
    }
}

// Test for dividing with zero in the denominator (should handle gracefully)
TEST(NeonCoreTest, DivFloatVectorsZeroDenominator) {
    const size_t size = 4;
    std::vector<float> a = {10.0f, 20.0f, 30.0f, 40.0f};
    std::vector<float> b = {0.0f, 0.0f, 0.0f, 0.0f};
    std::vector<float> result(size, 0.0f);

    // Expect std::runtime_error to be thrown
    EXPECT_THROW({
        neoncore::div_float_arrays(a.data(), b.data(), result.data(), size);
    }, std::runtime_error);
}
