
#ifndef TEST_REGISTER_H
#define TEST_REGISTER_H

class Test;

/**
 * declaration of function that returns test-suites.
 */
typedef Test* (*suiteFunc)();

/**
 * 
 */
class TestRegister
{
public:
  TestRegister(suiteFunc func);
  ~TestRegister();

  static Test* makeTest();  /**< return test-suites */
};

#endif  // TEST_REGISTER_H

