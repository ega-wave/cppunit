
#include "TestLog.h"
#include "Test.h"
#include <iostream>

void printStatus(TestLog::Status status);

TestLog::TestLog(const Test* test)
: status_(TEST_LOG_NOT_TESTED), test_(test), message_(""), filename_(0), line_(0), testedTime_(std::time(0))
{
}

TestLog::~TestLog()
{
}

TestLog::Status
TestLog::getStatus() const
{
  return status_;
}

std::string
TestLog::getMessage() const
{
  return message_;
}

const char*
TestLog::getFileName() const
{
  return filename_;
}

long
TestLog::getLine() const
{
  return line_;
}

unsigned int
TestLog::getTestNumber() const
{
  return test_->getNumber();
}

const char*
TestLog::getTestName() const
{
  return test_->getName();
}

std::time_t
TestLog::getTestedTime()
{
  return testedTime_;
}

void
TestLog::set(Status status)
{
  status_ = status;
  printStatus(status);
}

void printStatus(TestLog::Status status)
{
  char c;
  switch (status)
  {
  case TestLog::TEST_LOG_NOT_TESTED:
    break;  // NOT_TESTEDはありえない...
  case TestLog::TEST_LOG_SUCCESS:
    c = '.';
    break;
  case TestLog::TEST_LOG_FAILURE:
    c = 'F';
    break;
  case TestLog::TEST_LOG_ERROR:
    c = 'E';
    break;
  default:
    break;  // ありえない...
  };
  std::cerr << c << std::flush;
}

void
TestLog::set(const std::string& mes, const char* filename, long line)
{
  message_ = mes;
  filename_ = filename;
  line_ = line;
}

