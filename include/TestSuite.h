
#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#ifndef TEST_H
#include "Test.h"
#endif  // TEST_H

class TestSuiteImpl;

/**
 * テストの集合をあらわす.
 */
class TestSuite : public Test
{
public:
  typedef Test::size_type size_type;

  explicit TestSuite(const char* testname);
  virtual ~TestSuite();

  virtual void run(TestResult* result);
  virtual const char* getName() const;
  virtual size_type getNumber() const;

  virtual void addTest(Test* test);  /**< テストを追加する */

private:
  TestSuiteImpl* impl_;
};

#endif  // TEST_SUITE_H

