ARPTEST_DIR ?= ./arptest

TEST_CFLAGS += -DARPTEST -I$(ARPTEST_DIR)/src -Wall -Werror
TEST_SOURCES += $(ARPTEST_DIR)/src/arptest.cpp

# attempt to determine the architecture
ifndef ARCH
MACHINE = $(shell gcc -dumpmachine)
ifneq (,$(findstring linux,$(MACHINE)))
	ARCH = lin
else ifneq (,$(findstring apple,$(MACHINE)))
	ARCH = mac
else ifneq (,$(findstring mingw,$(MACHINE)))
	ARCH = win
else
	$(error Could not determine machine type. Try hacking around in arch.mk)
endif
endif

ifeq ($(ARCH), lin)
	TEST_CPP ?= g++
endif
ifeq ($(ARCH), mac)
	TEST_CPP ?= clang++
	TEST_CFLAGS += -std=c++11
	TEST_LDFLAGS += -std=c++11 -stdlib=libc++
endif
ifeq ($(ARCH), win)
	TEST_CPP ?= g++
endif


build/test/%.cpp.o: %.cpp
	@mkdir -p $(@D)
	$(TEST_CPP) $(TEST_CFLAGS) -c -o $@ $<

TEST_OBJ += $(patsubst %, build/test/%.o, $(TEST_SOURCES))

test: $(TEST_OBJ)
	$(TEST_CPP) -o build/testrunner $(TEST_OBJ) $(TEST_LDFLAGS)
