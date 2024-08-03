
#include "TestFormatter.h"
#include <iostream>
#include "TestLog.h"
#include <sstream>
#include "TestSummary.h"

void
TestFormatter::print(TestLog* log) const
{
  std::ostringstream buf;
  buf << log->getTestNumber() << "\t" << log->getTestName() << "\t";
  switch (log->getStatus()) {
  case TestLog::TEST_LOG_NOT_TESTED:
    buf << "N" << "\t\t";
    break;
  case TestLog::TEST_LOG_SUCCESS:
    buf << "o" << "\t\t";
    break;
  case TestLog::TEST_LOG_FAILURE:
    buf << "x";
    buf << "\t" << log->getFileName() << ":" << log->getLine() << "\t" << log->getMessage();
    break;
  case TestLog::TEST_LOG_ERROR:
    buf << "E";
    buf << "\t" << log->getFileName() << ":" << log->getLine() << "\t" << log->getMessage();
    break;
  default:
    break;
  };
  char timebuf[32];
  std::time_t testedTime = log->getTestedTime();
  std::strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", std::localtime(&testedTime));
  buf << "\t" << timebuf;
  std::cout << buf.str() << std::endl;
}

void
TestFormatter::print(const TestSummary* summary) const
{
  std::cerr << std::endl;
  if (summary->wasSuccessful()) {
    std::cerr << "OK (" << summary->getSucceeded() << " tests)" << std::endl;
  } else {
    std::cerr << "Run : " << (summary->getSucceeded() + summary->getFailured() + summary->getErrored()) << " tests, Not-Run : " << summary->getNotTested() << " tests." << std::endl;
    std::cerr << "Succeed : " << summary->getSucceeded() << " tests." << std::endl;
    std::cerr << "Failure : " << summary->getFailured() << " tests." << std::endl;
    std::cerr << "Error   : " << summary->getErrored() << " tests." << std::endl;
  }
}

