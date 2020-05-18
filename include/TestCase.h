
#ifndef TEST_CASE_H
#define TEST_CASE_H

#ifndef TEST_H
#include "Test.h"
#endif  // TEST_H

class TestResult;
class TestLog;
class TestAssertFunctorBase;

/**
 * テストケースを表わすクラス.
 * 個々のテストケースはすべて、このクラスを継承すること.
 */
class TestCase : public Test
{
public:
  typedef Test::size_type size_type;

  TestCase(size_type testnum, const char* testname);
  virtual ~TestCase();

  virtual void run(TestResult* result);
  virtual const char* getName() const;
  virtual size_type getNumber() const;

  virtual void setUp();  /**< テストの前準備を行なう、テンプレートメソッド */
  virtual void runTest() = 0;  /**< 実際のテストを行なう、テンプレートメソッド */
  virtual void tearDown();  /**< テストの後始末を行なう、テンプレートメソッド */

  virtual TestLog* createLog(const Test* test);  /**< このテストの結果のログを作成する */
  virtual TestLog* getLog();  /**< このテストのログを返す */
  virtual void addLog(TestLog* log);  /**< ログをTestResultクラスに追加する */

  virtual bool cppunit_assert(const TestAssertFunctorBase& functor, const char* filename, long line);  /**< テストの結果比較を行なう */

private:
  size_type testNum_;
  const char* testName_;

  TestResult* result_;
  TestLog* log_;
};

#endif  // TEST_CASE_H

