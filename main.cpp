#include "include/logger/logger.h"
#include <iostream>

int main(int argc, char* argv[]) {

  // Set the logging level of our application to INFO
  logging::LogMessage::LoggingLevel() = logging::LogLevel::Info;

  // In theory debug should not appear but because the check of logging level
  // is now in the macro it will appear
  logging::LogMessage().Get(logging::LogLevel::Error) << "Error test";
  logging::LogMessage().Get(logging::LogLevel::Warning) << "Warning test";
  logging::LogMessage().Get(logging::LogLevel::Info) << "Info test";
  logging::LogMessage().Get(logging::LogLevel::Debug) << "Debug test";

  // Using the macro LOG() will correcly check the applications logging level
  // and not output debug
  LOG(logging::LogLevel::Error) << "Error test 2";
  LOG(logging::LogLevel::Warning) << "Warning test 2";
  LOG(logging::LogLevel::Info) << "Info test 2";
  LOG(logging::LogLevel::Debug) << "Debug test 2";

  // Use the named marcos. Debug should not appear
  LOG_ERROR << "Error test 3";
  LOG_WARNING << "Warning test 3";
  LOG_INFO << "Info test 3";
  LOG_DEBUG << "Debug test 3";

}