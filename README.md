# cppunit
my x-unit for C++

# supported configuration
- gcc version 8.3.0 (Raspbian 8.3.0-6+rpi1)
- Any C++ compiler that supports C++03

# how to build
Just issue 'make' command on the top of the directory.

```bash
$ make
```

It produces .o files under the source/ directory.

# how to use
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
$ g++ -g -c -I../include/ IntegerTest.cpp -o IntegerTest.o
$ g++ -g IntegerTest.o ../source/*.o
```

4. run the test
```bash
$ ./a.out
.1              ○                       2020/05/18 17:01:46

OK (1 tests)
```

That's it.
