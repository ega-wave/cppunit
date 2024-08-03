
#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

class TestResult;
class Test;
class TestRunnerImpl;

/**
 *
 */
class TestRunner
{
public:
  TestRunner();
  ~TestRunner();

  void run(TestResult* result);  /**<  */
  void addTest(Test* test);  /**<  */

private:
  TestRunnerImpl* impl_;
};

#endif  // TEST_RUNNER_H

