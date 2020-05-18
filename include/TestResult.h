
#ifndef TEST_RESULT_H
#define TEST_RESULT_H

class TestLog;
class TestResultImpl;
class TestFormatter;

/**
 * テスト結果の集合を表わすクラス.
 */
class TestResult
{
public:
  TestResult();
  ~TestResult();

  virtual void addLog(TestLog* log);  /**< テスト結果を追加する */
  virtual void print(TestFormatter* format);  /**< テスト結果を出力する */
  virtual void printSummary(TestFormatter* format);  /**< テストのサマリを出力する */

private:
  TestResultImpl* impl_;
};

#endif  // TEST_RESULT_H

