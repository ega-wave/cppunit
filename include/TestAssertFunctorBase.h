
#ifndef TEST_ASSERT_FUNCTOR_BASE_H
#define TEST_ASSERT_FUNCTOR_BASE_H

#ifndef TEST_STRING
#define TEST_STRING
#include <string>
#endif  // TEST_STRING

/**
 * abstract class for TestAssertFunctor.
 */
class TestAssertFunctorBase
{
public:
  virtual ~TestAssertFunctorBase() {}
  virtual bool operator()() const = 0;  /**< return assert() */
  virtual std::string assertMessage() const = 0;  /**< return a message in case of test-failure */
};

/**
 * functor for a C-style string (T = const char*, C = std::equal_to<>).
 */
class TestAssertStringEqualFunctor : public TestAssertFunctorBase
{
public:
  TestAssertStringEqualFunctor(const char* expected, const char* actual);
  virtual bool operator()() const;
  virtual std::string assertMessage() const;
private:
  const char* expected_;
  const char* actual_;
};

#endif  // TEST_ASSERT_FUNCTOR_BASE_H

