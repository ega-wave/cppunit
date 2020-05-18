
#ifndef TEST_SUMMARY_H
#define TEST_SUMMARY_H

#ifndef TEST_H
#include "Test.h"
#endif  // TEST_H

class TestLog;
class TestFormatter;

class TestSummary
{
public:
  typedef Test::size_type size_type;

  TestSummary();
  ~TestSummary();

  void countUp(const TestLog* log);
  void print(const TestFormatter* format) const;

  size_type getSucceeded() const;
  size_type getFailured() const;
  size_type getErrored() const;
  size_type getNotTested() const;

  bool wasSuccessful() const;
  
private:
  size_type succeeded_;
  size_type failured_;
  size_type errored_;
  size_type notTested_;
};

#endif  // TEST_SUMMARY_H

