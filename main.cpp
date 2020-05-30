#include "include/logger/logger.h"
#include <iostream>

int main(int argc, char* argv[]) {

  // Set the logging level of our application to INFO
  Log::LoggingLevel() = logging::LogLevel::Info;

  // Using the macro LOG() will correcly check the applications logging level
  // and not output debug
  LOG(logging::LogLevel::Error) << "Error test 1";
  LOG(logging::LogLevel::Warning) << "Warning test 1";
  LOG(logging::LogLevel::Info) << "Info test 1";
  LOG(logging::LogLevel::Debug) << "Debug test 1";

  // Use the named marcos. Debug should not appear
  LOG_ERROR << "Error test 2";
  LOG_WARNING << "Warning test 2";
  LOG_INFO << "Info test 2";
  LOG_DEBUG << "Debug test 2";

  // Set the output to go to a file
  logging::LogToFile::LogStream() = fopen("example_log.txt", "a");

  LOG(logging::LogLevel::Error) << "Error test 3";
  LOG(logging::LogLevel::Warning) << "Warning test 3";
  LOG(logging::LogLevel::Info) << "Info test 3";
  LOG(logging::LogLevel::Debug) << "Debug test 3";

  // Use the named marcos. Debug should not appear
  LOG_ERROR << "Error test 4";
  LOG_WARNING << "Warning test 4";
  LOG_INFO << "Info test 4";
  LOG_DEBUG << "Debug test 4";
}