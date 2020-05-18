
#include "TestRegister.h"
#include <vector>
#include "TestSuite.h"

static std::vector<suiteFunc>* suiteFuncVec = 0;

TestRegister::TestRegister(suiteFunc func)
{
  if (! suiteFuncVec) suiteFuncVec = new std::vector<suiteFunc>();
  suiteFuncVec->push_back(func);
}

TestRegister::~TestRegister()
{
  if (! suiteFuncVec) {
    delete suiteFuncVec;
    suiteFuncVec = 0;
  }
}

Test*
TestRegister::makeTest()
{
  typedef std::vector<suiteFunc>::iterator suite_itr;
  TestSuite* suite = new TestSuite("All Tests");

  if (! suiteFuncVec) return suite;
  
  for (suite_itr itr = suiteFuncVec->begin();
      itr != suiteFuncVec->end(); ++itr) {
    suiteFunc func = *itr;
    suite -> addTest(func());
  }
  
  return suite;
}

