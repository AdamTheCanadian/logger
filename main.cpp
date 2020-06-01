#include "include/logger/logger.h"
#include <iostream>

int main(int argc, char* argv[]) {

  // Set the logging level of our application to INFO
  Log::LoggingLevel() = logging::LogLevel::Info;


  // Use the named marcos. Debug should not appear
  LOG_ERROR << "Error test 2";
  LOG_WARNING << "Warning test 2";
  LOG_INFO << "Info test 2";
  LOG_DEBUG << "Debug test 2";

  // Set the output to go to a file
  logging::LogToFile::LogStream() = fopen("example_log.txt", "a");

  // Use the named marcos. Debug should not appear
  LOG_ERROR << "Error test 4";
  LOG_WARNING << "Warning test 4";
  LOG_INFO << "Info test 4";
  LOG_DEBUG << "Debug test 4";
}