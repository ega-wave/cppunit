
#ifndef TEST_FORMATTER_H
#define TEST_FORMATTER_H

class TestLog;
class TestSummary;

/**
 * テスト結果のログを出力するクラス.
 */
class TestFormatter
{
public:
  virtual void print(TestLog* log) const;  /**< テスト結果のログを出力する */
  virtual void print(const TestSummary* summary) const;  /**< テスト結果のサマリを出力する */
};

#endif  // TEST_FORMATTER_H

