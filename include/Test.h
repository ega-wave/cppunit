
#ifndef TEST_H
#define TEST_H

#ifndef TEST_STD_CSTDDEF_H
#define TEST_STD_CSTDDEF_H
#include <cstddef>
#endif // TEST_STD_CSTDDEF_H

class TestResult;

/**
 * abstract class that represents a test
 */
class Test
{
public:
  typedef std::size_t size_type;

  virtual ~Test();

  virtual void run(TestResult* result) = 0; /**< run me (do a test) */
  virtual const char* getName() const = 0;  /**< return test's name */
  virtual size_type getNumber() const = 0;  /**< return test no. */
};

#endif  // TEST_H

