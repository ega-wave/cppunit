
#include "TestAssertFunctorBase.h"
#include <cstring>

/**
 * constructor.
 */
TestAssertStringEqualFunctor::TestAssertStringEqualFunctor(const char* expected, const char* actual)
: expected_(expected), actual_(actual)
{
}

bool
TestAssertStringEqualFunctor::operator()() const
{
  return std::strcmp(expected_, actual_) == 0;
}

std::string
TestAssertStringEqualFunctor::assertMessage() const
{
  std::string mes;
  mes += "expected:<";
  mes += expected_;
  mes += ">, but was:<";
  mes += actual_;
  mes += ">";
  return mes;
}

