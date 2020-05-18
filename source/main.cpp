
#include "TestRunner.h"
#include "TestResult.h"
#include "TestRegister.h"

int main()
{
	TestRunner runner;
	TestResult result;

	runner.addTest(TestRegister::makeTest());
	runner.run(&result);

	return 0;
}

