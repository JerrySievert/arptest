#pragma once

#include <vector>

namespace rack {
  // basic plugin definition
  class Plugin {
    public:
      const char *slug;
      const char *version;
      const char *website;
      const char *manual;
  };

  // params
  struct Param {
    float value = 0.0f;
  };

  // lights
  struct Light {
    float value = 0.0f;
  };

  // inputs
  struct Input {
    float value = 0.0f;
    bool active = false;
  };

  // outputs
  struct Output {
    float value = 0.0f;
    bool active = false;
  };

  // basic module definition
  struct Module {
    public:
      std::vector<Param> params;
      std::vector<Input> inputs;
      std::vector<Output> outputs;
      std::vector<Light> lights;
      Module (int numParams, int numInputs, int numOutputs, int numLights = 0) {
        params.resize(numParams);
        inputs.resize(numInputs);
        outputs.resize(numOutputs);
        lights.resize(numLights);
      }
      virtual void step ( ) { }
      virtual void onSampleRateChange ( ) { }
      virtual void reset ( ) { }
      virtual void randomize ( ) { }
  };

  struct Model {

  };

  struct TextField {
    TextField() { };
    char *text;
  };

  // utility functions
  float clamp (float, float, float);
  float engineGetSampleRate ( );
  float engineGetSampleTime ( );
}
