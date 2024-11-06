#include <gtest/gtest.h>
#include "neoncore/neoncore.h"  // Include the main NeonCore header

// Test for adding two float arrays
TEST(NeonCoreTest, AddFloatArrays) {
    const size_t size = 8;
    float a[size] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f};
    float b[size] = {8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f};
    float result[size] = {0.0f};

    // Call the add_float_arrays function from the NeonCore library
    neoncore::add_float_arrays(result, a, b, size);

    // Expected result after adding the two arrays element-wise
    float expected[size] = {9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f};

    // Compare the result with the expected values
    for (size_t i = 0; i < size; ++i) {
        EXPECT_NEAR(result[i], expected[i], 1e-6f);  // Floating-point comparison with tolerance
    }
}

// Test for adding two arrays of different sizes (edge case)
TEST(NeonCoreTest, AddFloatArraysDifferentSizes) {
    const size_t size = 5;
    float a[size] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    float b[size] = {5.0f, 4.0f, 3.0f, 2.0f, 1.0f};
    float result[size] = {0.0f};

    // Call the add_float_arrays function
    neoncore::add_float_arrays(result, a, b, size);

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
    neoncore::add_float_arrays(result, a, b, size);

    // Expected result (b array itself, since a is all zeros)
    float expected[size] = {1.0f, 2.0f, 3.0f, 4.0f};

    // Compare the result with the expected values
    for (size_t i = 0; i < size; ++i) {
        EXPECT_NEAR(result[i], expected[i], 1e-6f);  // Floating-point comparison with tolerance
    }
}
