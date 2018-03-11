#pragma once

#include <cstdint>

extern uint16_t arp_test_passed;
extern uint16_t arp_test_failed;

struct arp_test {
  uint8_t (*func)();
  const char *name;
};

void _test_fail (const char *, const char *, uint16_t);
void _test_pass (const char *);
void _test_start (const char *);
void _add_test (uint8_t (*)(), const char *);

void arptest_init ();

/* Successfull end of the test case */
#define done() return 0

/* Check single condition */
#define check(cond, message) do { if (!(cond)) { _test_fail(message, __FILE__, __LINE__); arp_test_failed++; } else { _test_pass(message); arp_test_passed++; } } while (0)

/* Test runner */
#define test(func, name) do { _test_start(name); func(); } while(0)

/* Add a test */
#define add_test(func, name) do { _add_test(func, name); } while(0)
