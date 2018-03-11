#include "ArpTestExample.hpp"


// The plugin-wide instance of the Plugin class
Plugin *plugin;

void init(rack::Plugin *p) {
	plugin = p;
	// This is the unique identifier for your plugin
	p->slug = TOSTRING(SLUG);
	p->version = TOSTRING(VERSION);
	p->website = "https://github.com/JerrySievert/ArpTest";
	p->manual = "https://github.com/JerrySievert/ArpTest/blob/master/README.md";

  // add each module
	p->addModel(modelMult);
}
