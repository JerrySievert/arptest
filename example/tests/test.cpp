#include "test.hpp"

// add all of the tests during initialization
// tests will run in this order
void arptest_init() {
  // Mult.cpp
  add_test(test_mult_instantiation, "Mult Module Instantiation");
  add_test(test_mult_input_and_output, "Mult Module Input/Output");
}
