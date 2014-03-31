#ifndef TESTCASE_H
#define TESTCASE_H

#include "headers.h"
class TestCase {
public:
  static const bool TESTCASE_NULL = false;
  TestCase(std::istream &);
  ~TestCase();
protected:
  istream &_input;
};

#endif
