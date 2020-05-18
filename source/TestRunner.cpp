
#include "TestRunner.h"
#include <list>
#include "Test.h"
#include "TestResult.h"
#include "TestFormatter.h"

// TestクラスのdeleteはTestRunnerが行なう

class TestRunnerImpl
{
public:
  typedef std::list<Test*> container_type;

  TestRunnerImpl() {}
  ~TestRunnerImpl();

  container_type& getTests() { return tests_; }

private:
  container_type tests_;
};

TestRunnerImpl::~TestRunnerImpl()
{
  typedef container_type::iterator test_itr;

  for (test_itr itr = tests_.begin(); itr != tests_.end(); ++itr) {
    delete *itr;
  };
}

TestRunner::TestRunner()
: impl_(new TestRunnerImpl())
{
}

TestRunner::~TestRunner()
{
  delete impl_;
}

void
TestRunner::run(TestResult* result)
{
  typedef TestRunnerImpl::container_type::iterator test_itr;

  for (test_itr itr = impl_->getTests().begin();
    itr != impl_->getTests().end(); ++itr) {
    (*itr) -> run(result);  // テスト実行
  };

  TestFormatter format_;
  result -> print(&format_);  // 結果出力

  result -> printSummary(&format_);  // サマリ出力
}

void
TestRunner::addTest(Test* test)
{
  impl_->getTests().push_back(test);
}

