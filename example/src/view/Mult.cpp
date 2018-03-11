#include "../controller/Mult.hpp"

struct MultWidget : ModuleWidget {
	MultWidget(MultModule *module);
};

MultWidget::MultWidget(MultModule *module) : ModuleWidget(module) {
	box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/Mult.svg")));
		addChild(panel);
	}

	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
	addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

	addInput(Port::create<PJ301MPort>(Vec(10, 34), Port::INPUT, module, MultModule::TOP_INPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 73), Port::OUTPUT, module, MultModule::FIRST_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 108), Port::OUTPUT, module, MultModule::SECOND_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 143), Port::OUTPUT, module, MultModule::THIRD_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 178), Port::OUTPUT, module, MultModule::FOURTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 213), Port::OUTPUT, module, MultModule::FIFTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 248), Port::OUTPUT, module, MultModule::SIXTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 283), Port::OUTPUT, module, MultModule::SEVENTH_OUTPUT));
	addOutput(Port::create<PJ301MPort>(Vec(10, 318), Port::OUTPUT, module, MultModule::EIGHTH_OUTPUT));
}

Model *modelMult = Model::create<MultModule, MultWidget>("ArpTestExample", "1x8 Multiplier", "1x8 Multipier", MIXER_TAG);
