
#ifndef TEST_REGISTER_H
#define TEST_REGISTER_H

class Test;

/**
 * テストケースの集合を返す関数の宣言.
 */
typedef Test* (*suiteFunc)();

/**
 * テストケースを自動的に集めるユーティリティクラス.
 */
class TestRegister
{
public:
  TestRegister(suiteFunc func);
  ~TestRegister();

  static Test* makeTest();  /**< テストケースの集合を返す */
};

#endif  // TEST_REGISTER_H

