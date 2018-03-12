# ARPTest

A Rack Plugin Test platform.

This project aims to emulate part of the [VCVRack](https://vcvrack.com/) environment
to allow for direct testing of plugins.

This is very much a work in progress, and only has coverage of a small amount of
functionality currently exposed by Rack.  This will change in time, as more testing
is needed.

This is also currently aimed at plugins created against Rack 0.6.0 and beyond.
Once a new version of Rack has been released, the goal is to be up to date with
it.

NOTE: currently, this is used to test the modules for the plugins, not the full
plugin, including instantiation.  Thus not all functionality is provided.

## Readying Your Code

Using ARPTest requires a small number of changes to your module code.

Firstly, a small change when including `rack.hpp`:

```
#include "rack.hpp"
```

would become:

```
#ifndef ARPTEST
#include "rack.hpp"
#else
#include "arprack.hpp"
#endif
```

Secondly, modules should be broken up in order to separate controller logic
from view logic.  The example, once again, shows a good method of doing this.
The separation allows for only the logic portion of the module to be tested,
as well as stubbed out, without the need of testing the UI.

Finally, some small changes and additions need to be made to your `Makefile`:

```
# Sources to test for ArpTest - this will usually only include your controllers
TEST_SOURCES += $(wildcard src/controller/*.cpp)

# Add any tests
TEST_SOURCES += $(wildcard tests/*.cpp)

# By default, ARPTEST_DIR is arptest in your current directory, but you can override it
ARPTEST_DIR ?= ./arptest

include $(ARPTEST_DIR)/build.mk
```

## Writing Tests

Tests are straightforward to create.

### tests/test.hpp

Define each of your tests in `test.hpp` (you need one of these for each test):

```c
uint8_t test_controller_instantiation();
```

### tests/test.cpp

Add a test initialization (you only need one of these):

```c
void apitest_init() {
  add_test(test_controller_instatiation, "Test Controller Instantiation");
}
```

### tests/mytest.cpp

And write a test or two (these should match those in `test.hpp` and `test.cpp`):

```c
uint8_t test_controller_instantiation() {
  MyController *controller = new MyController();

  // check that the controller exists
  check(controller, "the controller exists!");

  // note that the test is complete
  done();
}
```

## Running Tests

Once tests are written, it is easy to build and run your tests:

```
$ make test
$ build/testrunner -s

Test Controller Instantiation
  ✓ the controller exists!
```

Note that running with the `-s` flag executes the tests with `spec` output,
whereas not including the flag will run the tests with `dot` output.

## Example

A full example of a module with tests can be found in [example](example/).
