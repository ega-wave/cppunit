
#ifndef TEST_RESULT_H
#define TEST_RESULT_H

class TestLog;
class TestResultImpl;
class TestFormatter;

/**
 * test-result.
 */
class TestResult
{
public:
  TestResult();
  ~TestResult();

  virtual void addLog(TestLog* log);  /**< */
  virtual void print(TestFormatter* format);  /**< */
  virtual void printSummary(TestFormatter* format);  /**< */

private:
  TestResultImpl* impl_;
};

#endif  // TEST_RESULT_H

