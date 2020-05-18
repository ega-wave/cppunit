
#ifndef TEST_H
#define TEST_H

#ifndef TEST_STD_CSTDDEF_H
#define TEST_STD_CSTDDEF_H
#include <cstddef>
#endif // TEST_STD_CSTDDEF_H

class TestResult;

/**
 * テストを表わすインターフェイスクラス.
 */
class Test
{
public:
  typedef std::size_t size_type;

  virtual ~Test();

  virtual void run(TestResult* result) = 0; /**< テストを実行する */
  virtual const char* getName() const = 0;  /**< テスト名を返す */
  virtual size_type getNumber() const = 0;  /**< テスト番号を返す */
};

#endif  // TEST_H

