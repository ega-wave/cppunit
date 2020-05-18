
#include "TestResult.h"
#include <list>
#include "TestFormatter.h"
#include "TestLog.h"
#include "TestSummary.h"

// TestLogクラスのdeleteはTestResultが行なう

class TestResultImpl
{
public:
  typedef std::list<TestLog*> container_type;

  TestResultImpl() {}
  ~TestResultImpl();

  container_type& getLogs() { return logs_; }

private:
  container_type logs_;
};

TestResultImpl::~TestResultImpl()
{
  typedef container_type::iterator log_itr;

  for (log_itr itr = logs_.begin(); itr != logs_.end(); ++itr) {
    delete *itr;
  };
}

TestResult::TestResult()
: impl_(new TestResultImpl())
{
}

TestResult::~TestResult()
{
  delete impl_;
}

void
TestResult::addLog(TestLog* log)
{
  impl_->getLogs().push_back(log);
}

void
TestResult::print(TestFormatter* format)
{
  typedef TestResultImpl::container_type::iterator log_itr;

  for (log_itr itr = impl_->getLogs().begin();
    itr != impl_->getLogs().end(); ++itr) {
    format->print(*itr);
  };
}

void
TestResult::printSummary(TestFormatter* format)
{
  typedef TestResultImpl::container_type::iterator log_itr;

  TestSummary summary;
  for (log_itr itr = impl_->getLogs().begin();
    itr != impl_->getLogs().end(); ++itr) {
    summary.countUp(*itr);
  };
  summary.print(format);
}

