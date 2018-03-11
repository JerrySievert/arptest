#include "Mult.hpp"

MultModule::MultModule() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
  // nothing to do here except initialize the parent class
}

void MultModule::step() {
	float in = inputs[TOP_INPUT].value;

	outputs[FIRST_OUTPUT].value = in;
	outputs[SECOND_OUTPUT].value = in;
	outputs[THIRD_OUTPUT].value = in;
	outputs[FOURTH_OUTPUT].value = in;
	outputs[FIFTH_OUTPUT].value = in;
	outputs[SIXTH_OUTPUT].value = in;
	outputs[SEVENTH_OUTPUT].value = in;
	outputs[EIGHTH_OUTPUT].value = in;
}
