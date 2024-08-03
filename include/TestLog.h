
#ifndef TEST_LOG_H
#define TEST_LOG_H

#ifndef TEST_STRING
#define TEST_STRING
#include <string>
#endif  // TEST_STRING

#ifndef TEST_CTIME
#define TEST_CTIME
#include <ctime>
#endif  // TEST_CTIME

class Test;

/**
 * the class that represents a log.
 */
class TestLog
{
public:
  enum Status { TEST_LOG_NOT_TESTED, TEST_LOG_SUCCESS, TEST_LOG_FAILURE, TEST_LOG_ERROR };  /**< the status of test-result */

  explicit TestLog(const Test* test);
  ~TestLog();

  Status getStatus() const;  /**<  */
  std::string getMessage() const;  /**< return a message in case of test-failure */
  const char* getFileName() const;  /**< return a source file's name in case of test-failure */
  long getLine() const;  /**< return a line-no of a source file in case of test-failure */
  unsigned int getTestNumber() const;  /**< return test number */
  const char* getTestName() const;  /**< return test name */
  std::time_t getTestedTime();  /**< return the time of test-execution */

  void set(Status status);  /**<  */
  void set(const std::string& mes, const char* filename, long line);  /**< set info in case of test-failure */

private:

  TestLog(const TestLog&);
  TestLog& operator=(const TestLog&);

  Status status_;
  const Test* test_;
  std::string message_;
  const char* filename_;
  long line_;
  std::time_t testedTime_;
};

#endif  // TEST_LOG_H

