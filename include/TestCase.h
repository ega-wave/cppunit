
#ifndef TEST_CASE_H
#define TEST_CASE_H

#ifndef TEST_H
#include "Test.h"
#endif  // TEST_H

class TestResult;
class TestLog;
class TestAssertFunctorBase;

/**
 * a class that represents a test-case.
 * Every test-case-class must derive TestCase as base-class.
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

  virtual void setUp();  /**< preparation */
  virtual void runTest() = 0;  /**< run me */
  virtual void tearDown();  /**< clean-up */

  virtual TestLog* createLog(const Test* test);  /**<  */
  virtual TestLog* getLog();  /**<  */
  virtual void addLog(TestLog* log);  /**<  */

  virtual bool cppunit_assert(const TestAssertFunctorBase& functor, const char* filename, long line);  /**< do assert() */

private:
  size_type testNum_;
  const char* testName_;

  TestResult* result_;
  TestLog* log_;
};

#endif  // TEST_CASE_H

