
all: source/Test.o source/TestAssertFunctorBase.o source/TestCase.o source/TestFormatter.o source/TestLog.o source/TestRegister.o source/TestResult.o source/TestRunner.o source/TestSuite.o source/TestSummary.o source/main.o

source/Test.o : source/Test.cpp
	bash compile.bash Test

source/TestAssertFunctorBase.o : source/TestAssertFunctorBase.cpp
	bash compile.bash TestAssertFunctorBase

source/TestCase.o : source/TestCase.cpp
	bash compile.bash TestCase

source/TestFormatter.o : source/TestFormatter.cpp
	bash compile.bash TestFormatter

source/TestLog.o : source/TestLog.cpp
	bash compile.bash TestLog

source/TestRegister.o : source/TestRegister.cpp
	bash compile.bash TestRegister

source/TestResult.o : source/TestResult.cpp
	bash compile.bash TestResult

source/TestRunner.o : source/TestRunner.cpp
	bash compile.bash TestRunner

source/TestSuite.o : source/TestSuite.cpp
	bash compile.bash TestSuite

source/TestSummary.o : source/TestSummary.cpp
	bash compile.bash TestSummary

source/main.o : source/main.cpp
	bash compile.bash main

clean:
	find . -name "*.o" | xargs rm

