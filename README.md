# Cppunit
my x-unit for C++

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

