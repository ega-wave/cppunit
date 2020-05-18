
#include "TestSummary.h"
#include "TestLog.h"
#include "TestFormatter.h"

TestSummary::TestSummary()
: succeeded_(0), failured_(0), errored_(0), notTested_(0)
{
}

TestSummary::~TestSummary()
{
}

void
TestSummary::countUp(const TestLog* log)
{
  switch (log->getStatus()) {
  case TestLog::TEST_LOG_NOT_TESTED:
    ++notTested_;
    break;
  case TestLog::TEST_LOG_SUCCESS:
    ++succeeded_;
    break;
  case TestLog::TEST_LOG_FAILURE:
    ++failured_;
    break;
  case TestLog::TEST_LOG_ERROR:
    ++errored_;
    break;
  default:
    break;
  };
}

void
TestSummary::print(const TestFormatter* format) const
{
  format->print(this);
}

TestSummary::size_type
TestSummary::getSucceeded() const
{
  return succeeded_;
}

TestSummary::size_type
TestSummary::getFailured() const
{
  return failured_;
}

TestSummary::size_type
TestSummary::getErrored() const
{
  return errored_;
}

TestSummary::size_type
TestSummary::getNotTested() const
{
  return notTested_;
}

bool
TestSummary::wasSuccessful() const
{
  return failured_ == 0 &&
      errored_ == 0 &&
      notTested_ == 0;
}

