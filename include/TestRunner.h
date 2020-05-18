
#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

class TestResult;
class Test;
class TestRunnerImpl;

/**
 * テストを実行するアプリケーションクラス.
 */
class TestRunner
{
public:
  TestRunner();
  ~TestRunner();

  void run(TestResult* result);  /**< テストを実行する */
  void addTest(Test* test);  /**< テストを追加する */

private:
  TestRunnerImpl* impl_;
};

#endif  // TEST_RUNNER_H

