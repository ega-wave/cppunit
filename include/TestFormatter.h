
#ifndef TEST_FORMATTER_H
#define TEST_FORMATTER_H

class TestLog;
class TestSummary;

/**
 * print-out formatter for log.
 */
class TestFormatter
{
public:
  virtual void print(TestLog* log) const;  /**<  */
  virtual void print(const TestSummary* summary) const;  /**<  */
};

#endif  // TEST_FORMATTER_H

