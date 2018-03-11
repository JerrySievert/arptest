#include "arptest.hpp"
#include "test.hpp"

#include "../src/controller/Mult.hpp"

// create a test to test the instantiation
uint8_t test_mult_instantiation() {
  // instantiate the module
  struct MultModule *module = new MultModule();

  check(module, "module is instantiated");

  done();
}


// create a test to test the input and output
uint8_t test_mult_input_and_output() {
  // instantiate the module
  struct MultModule *module = new MultModule();

  // set the input to high
  module->inputs[0].value = 1.0f;

  // run the step function once
  module->step();

  check(module->inputs[0].value == 1.0f, "input value is correct (1.0f)");

  check(module->outputs[0].value == 1.0f, "output value (0) is correct (1.0f)");
  check(module->outputs[1].value == 1.0f, "output value (1) is correct (1.0f)");
  check(module->outputs[2].value == 1.0f, "output value (2) is correct (1.0f)");
  check(module->outputs[3].value == 1.0f, "output value (3) is correct (1.0f)");
  check(module->outputs[4].value == 1.0f, "output value (4) is correct (1.0f)");
  check(module->outputs[5].value == 1.0f, "output value (5) is correct (1.0f)");
  check(module->outputs[6].value == 1.0f, "output value (6) is correct (1.0f)");
  check(module->outputs[7].value == 1.0f, "output value (7) is correct (1.0f)");

  // set the input to low
  module->inputs[0].value = 0.0f;

  // run the step function once
  module->step();

  check(module->inputs[0].value == 0.0f, "input value is correct (0.0f)");

  check(module->outputs[0].value == 0.0f, "output value (0) is correct (0.0f)");
  check(module->outputs[1].value == 0.0f, "output value (1) is correct (0.0f)");
  check(module->outputs[2].value == 0.0f, "output value (2) is correct (0.0f)");
  check(module->outputs[3].value == 0.0f, "output value (3) is correct (0.0f)");
  check(module->outputs[4].value == 0.0f, "output value (4) is correct (0.0f)");
  check(module->outputs[5].value == 0.0f, "output value (5) is correct (0.0f)");
  check(module->outputs[6].value == 0.0f, "output value (6) is correct (0.0f)");
  check(module->outputs[7].value == 0.0f, "output value (7) is correct (0.0f)");

  // signal that the test is complete
  done();
}
