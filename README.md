# Cppunit
my x-unit for C++

# Differences with any other kind of CppUnit
1. You can call setUp() and tearDown() method on *EVERY* test.

Here is a example.

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

On other CppUnit, You can call these methods only one time during execution of all IntegerTest's test method.

If IntegerTest<1>::runTest() doesn't need any setUp() or tearDown() method, you can simply comment it out.

2. You don't worry about the name of your test method.

To add a test, only you have to do is to write IntegerTest<2>::runTest() method.
Instead, you can describe explanation about a test as a literal string.

```C++
  suite->addTest(new IntegerTest<2>("subtract test"));
```

# Supported configuration
- gcc version 8.3.0 (Raspbian 8.3.0-6+rpi1)
- Any C++ compiler that supports C++98

# How to build
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

# About TEST_ASSERT_* Macros
As for now, these 2 macros are implemented.

- TEST_ASSERT_EQUALS
- TEST_ASSERT_NOT_EQUALS

That's it.

