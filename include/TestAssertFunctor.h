
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

// privateメンバにアクセスするためのマクロ
// (Target)Friendクラスに、メンバ(const ターゲット&) const関数が定義されてる必要あり
#define TEST_PRIVATE_ACCESS(var, member) (member(var))

///////////////////////////// makeMessage関数 ///////////////////////////
/**
 * makeMessage関数(operator==()版).
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
 * makeMessage関数(operator!=()版).
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
 * assert関数オブジェクト.
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

/*****************************************************
 * ここより下で実装する。実装するのは、
 * ・ASSERTマクロ
 * ・上のTestAssertFunctorクラステンプレート生成関数
 * ・makeMessage関数
 * 現在、operator==()とoperator!=()を実装
 *****************************************************/

///////////////////////////// ASSERTマクロ //////////////////////////////
#define TEST_ASSERT_EQUALS(expect, actual) \
  if (! cppunit_assert(makeTestAssertEqualFunctor(expect, actual), __FILE__, __LINE__)) return
#define TEST_ASSERT_NOT_EQUALS(not_expect, actual) \
  if (! cppunit_assert(makeTestAssertNotEqualFunctor(not_expect, actual), __FILE__, __LINE__)) return
#define TEST_ASSERT_STRING_EQUALS(expect, actual) \
  if (! cppunit_assert(TestAssertStringEqualFunctor(expect, actual), __FILE__, __LINE__)) return

/////////////////////////// TestAssertFunctorクラステンプレート生成関数
/**
 * TestAssertFunctorクラステンプレート生成関数(operator==()版).
 */
template <typename T>
TestAssertFunctor<T, std::equal_to<T> >
makeTestAssertEqualFunctor(const T& expect, const T& actual)
{
  return TestAssertFunctor<T, std::equal_to<T> >(expect, actual);
}

/**
 * TestAssertFunctorクラステンプレート生成関数(operator!=()版).
 */
template <typename T>
TestAssertFunctor<T, std::not_equal_to<T> >
makeTestAssertNotEqualFunctor(const T& not_expect, const T& actual)
{
  return TestAssertFunctor<T, std::not_equal_to<T> >(not_expect, actual);
}

#endif  // TEST_ASSERT_FUNCTOR_H

