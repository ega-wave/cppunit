
#ifndef TEST_ASSERT_FUNCTOR_H
#define TEST_ASSERT_FUNCTOR_H

#ifndef TEST_SSTREAM
#define TEST_SSTREAM
#include <sstream>
#endif  // TEST_SSTREAM

#ifndef TEST_FUNCTIONAL
#define TEST_FUNCTIONAL
#include <functional>
#endif  // TEST_FUNCTIONAL

#ifndef TEST_ASSERT_FUNCTOR_BASE_H
#include "TestAssertFunctorBase.h"
#endif  // TEST_ASSERT_FUNCTOR_BASE_H


///////////////////////////// makeMessage関数 ///////////////////////////
/**
 * makeMessage function (std::equal_to<T>() version).
 */
template <typename T>
std::string
makeMessage(const T& expected, const T& actual, const std::equal_to<T>&)
{
  std::ostringstream buf;
  buf << "expected:<" << expected << ">, but was:<" << actual << ">";
  return buf.str();
}

/**
 * makeMessage function (std::not_equal_to<T>() version).
 */
template <typename T>
std::string
makeMessage(const T& not_expected, const T&, const std::not_equal_to<T>&)
{
  std::ostringstream buf;
  buf << "not expected:<" << not_expected << ">, but was detected";
  return buf.str();
}

/**
 * a functor for assert.
 */
template <typename T, typename C>  // C = functor<T> e.g. std::equal_to<T>
class TestAssertFunctor : public TestAssertFunctorBase
{
public:
  TestAssertFunctor(const T& expected, const T& actual)
  : expected_(expected), actual_(actual) {}
  virtual bool operator()() const { return C()(expected_, actual_); }
  virtual std::string assertMessage() const {
    return makeMessage(expected_, actual_, C());
  }
private:
  const T& expected_;
  const T& actual_;
};


///////////////////////////// ASSERT macro //////////////////////////////
#define TEST_ASSERT_EQUALS(expect, actual) \
  if (! cppunit_assert(makeTestAssertEqualFunctor(expect, actual), __FILE__, __LINE__)) return
#define TEST_ASSERT_NOT_EQUALS(not_expect, actual) \
  if (! cppunit_assert(makeTestAssertNotEqualFunctor(not_expect, actual), __FILE__, __LINE__)) return
#define TEST_ASSERT_STRING_EQUALS(expect, actual) \
  if (! cppunit_assert(TestAssertStringEqualFunctor(expect, actual), __FILE__, __LINE__)) return

/////////////////////////// make-function for a functor
/**
 * make-function for a TestAssertFunctor (std::equal_to<T> version).
 */
template <typename T>
TestAssertFunctor<T, std::equal_to<T> >
makeTestAssertEqualFunctor(const T& expect, const T& actual)
{
  return TestAssertFunctor<T, std::equal_to<T> >(expect, actual);
}

/**
 * make-function for a TestAssertFunctor (std::not_equal_to<T> version).
 */
template <typename T>
TestAssertFunctor<T, std::not_equal_to<T> >
makeTestAssertNotEqualFunctor(const T& not_expect, const T& actual)
{
  return TestAssertFunctor<T, std::not_equal_to<T> >(not_expect, actual);
}

#endif  // TEST_ASSERT_FUNCTOR_H

