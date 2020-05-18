
#include "TestCase.h"
#include "TestResult.h"
#include "TestLog.h"
#include "TestAssertFunctorBase.h"

TestCase::TestCase(size_type testnum, const char* testname)
: testNum_(testnum), testName_(testname)
{
}

TestCase::~TestCase()
{
}

void
TestCase::setUp()
{
}

void
TestCase::tearDown()
{
}

const char*
TestCase::getName() const
{
  return testName_;
}

TestCase::size_type
TestCase::getNumber() const
{
  return testNum_;
}

void
TestCase::run(TestResult* result)
{
  result_ = result;
  log_ = createLog(this);

  setUp();
  runTest();
  tearDown();

  addLog(log_);
}

TestLog*
TestCase::createLog(const Test* test)
{
  return new TestLog(test);
}

TestLog*
TestCase::getLog()
{
  return log_;
}

void
TestCase::addLog(TestLog* log)
{
  result_ -> addLog(log);
}

bool
TestCase::cppunit_assert(const TestAssertFunctorBase& functor, const char* filename, long line)
{
  if (! functor()) {
    getLog() -> set(functor.assertMessage(), filename, line);
    getLog() -> set(TestLog::TEST_LOG_FAILURE);
    return false;
  };

  getLog() -> set(TestLog::TEST_LOG_SUCCESS);
  return true;
}

