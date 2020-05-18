
#include "TestSuite.h"
#include <list>

class TestSuiteImpl
{
public:
  typedef std::list<Test*> container_type;

  explicit TestSuiteImpl(const char* testname)
  : tests_(), testname_(testname) {}
  ~TestSuiteImpl();

  container_type& getTests() { return tests_; }
  const char* getTestName() const { return testname_; }

private:
  container_type tests_;
  const char* testname_;
};

TestSuiteImpl::~TestSuiteImpl()
{
  typedef container_type::iterator test_itr;

  for (test_itr itr = tests_.begin(); itr != tests_.end(); ++itr) {
    delete *itr;
  };
}

TestSuite::TestSuite(const char* testname)
: impl_(new TestSuiteImpl(testname))
{
}

TestSuite::~TestSuite()
{
  delete impl_;
}

void
TestSuite::run(TestResult* result)
{
  typedef TestSuiteImpl::container_type::iterator test_itr;
  for (test_itr itr = impl_->getTests().begin();
      itr != impl_->getTests().end(); ++itr) {
    (*itr) -> run(result);
  }
}

const char*
TestSuite::getName() const
{
  return impl_->getTestName();
}

TestSuite::size_type
TestSuite::getNumber() const
{
  return 0;
}

void
TestSuite::addTest(Test* test)
{
  impl_->getTests().push_back(test);
}

