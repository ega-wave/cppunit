
#include "TestAssertFunctorBase.h"
#include <cstring>
//#if !defined(WIN32) && !defined(_RWCONFIG)
//namespace std {
//  using ::strcmp;
//}
//#endif  // _RWCONFIG

/**
 * コンストラクタ.
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

