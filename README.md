# CppUnit (ega-wave version)
xUnit for C++ built from scratch.

# Features that differ with other CppUnit
1. You can call setUp() and/or tearDown() method on *EVERY* test.

Here is an example.
Executed in the order IntegerTest<1>::setUp(), IntegerTest<1>::runTest(), IntegerTest<1>::tearDown().

```C++
template <>
void
IntegerTest<1>::setUp()
{
  /* set-up for IntegerTest<1>::runTest() */
}

template <>
void
IntegerTest<1>::runTest()
{
  Integer i(1);
  TEST_ASSERT_EQUALS(int(1),i.get());
}

template <>
void
IntegerTest<1>::tearDown()
{
  /* tear-down for IntegerTest<1>::runTest() */
}
```

If no setUp() and/or tearDown() method needed, you can simply comment it out or remove it.

2. You can avoid from naming for your test method

In CppUnit, you must declare and implement methods XxxTest::testSomething1ToTest(), XxxTest::testSomething2ToTest(), and so on.
It is hard work for you to decide it's name.

But with my CppUnit, to add a test, you should implement IntegerTest<2>::runTest() method.
To add one more test, it is sufficient to implement IntegerTest<3>::runTest() method.
In this way, addding tests is very easy, but don't forget to call TestSuite::addTest(new XxxTest<N>()).
The argment of the constructor (XxxTest<N>::XxxTest<N>(const char*)) is a description being tested and is passed as a literal string.

```C++
  suite->addTest(new IntegerTest<2>("subtract test"));
```

# Supported configuration
- Any C++ compiler that supports C++98 or later.

# How to compile
Just issue 'make' command on the top of the directory.

```bash
$ make
```

It produces .o files under the source/ directory.

# How to use
1. Generate ClassTest.cpp. "Class" is the class which you want to test on.

```bash
$ cd bin
$ bash gentest.bash Class
```

2. Write test using TEST_ASSERT_* macros.

```c++
template <>
void
ClassTest<1>::runTest()
{
  TEST_ASSERT_EQUALS(2, 1+1);
}
```

3. build
```bash
$ g++ -g -c -I../include/ ClassTest.cpp -o ClassTest.o
$ g++ -g ClassTest.o ../source/*.o
```

4. run the test
```bash
$ ./a.out
.1              ○                       2020/05/18 17:01:46

OK (1 tests)
```

That's it.

# About TEST_ASSERT_* Macros
As for now, these 2 macros are implemented.

- TEST_ASSERT_EQUALS
- TEST_ASSERT_NOT_EQUALS

Thanks.
