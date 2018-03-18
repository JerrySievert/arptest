#include <iostream>
#include <vector>
#include <cstring>
#include "arptest.hpp"

using namespace std;

bool arp_spec = 0;
uint16_t arp_test_passed = 0;
uint16_t arp_test_failed = 0;

std::vector<struct arp_test> tests;

void _test_pass (const char *message) {
  if (arp_spec) {
    cout << "  ✓ " << message << endl;
  } else {
    cout << ".";
  }
}

void _test_fail (const char *message, const char *file, uint16_t line) {
  if (arp_spec) {
    cout << "  𝙭 " << message << " (" << file << ":" << line << ")" << endl;
  } else {
    cout << "𝙭";
  }
}

void _test_start (const char *name) {
  if (arp_spec) {
    cout << endl << name << endl;
  }
}

void _add_test (uint8_t (*func)(), const char *name) {
  struct arp_test t = { func, name };
  tests.push_back(t);
}

int main (int argc, char **argv) {
  if (argc > 1) {
    if ((strcmp(argv[1], "--spec") == 0) || (strcmp(argv[1], "-s") == 0)) {
      arp_spec = 1;
    }
  }

  arptest_init();

  for (struct arp_test t : tests) {
    test(t.func, t.name);
  }

  cout << endl << "PASSED: " << arp_test_passed << endl << "FAILED: " << arp_test_failed << endl;

  return (arp_test_failed > 0 ? 1 : 0);
}


namespace rack {
  // utility functions
  float clamp (float in, float min, float max) { return (in < min) ? min : (in > max) ? max : in; }
}
