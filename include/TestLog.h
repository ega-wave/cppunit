
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
 * テスト結果のログを表わすクラス.
 */
class TestLog
{
public:
  enum Status { TEST_LOG_NOT_TESTED, TEST_LOG_SUCCESS, TEST_LOG_FAILURE, TEST_LOG_ERROR };  /**< テスト結果を表わす */

  explicit TestLog(const Test* test);
  ~TestLog();

  Status getStatus() const;  /**< テスト結果を返す */
  std::string getMessage() const;  /**< テストに失敗した時のメッセージを返す */
  const char* getFileName() const;  /**< テストに失敗した時のテストが記述されているファイル名を返す */
  long getLine() const;  /**< テストに失敗した時の行番号を返す */
  unsigned int getTestNumber() const;  /**< テスト番号を返す */
  const char* getTestName() const;  /**< テスト名を返す */
  std::time_t getTestedTime();  /**< テストした時刻を返す */

  void set(Status status);  /**< テスト結果をセットする */
  void set(const std::string& mes, const char* filename, long line);  /**< テストに失敗した時の情報をセットする */

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

