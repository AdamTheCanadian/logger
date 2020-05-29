#include "include/logger/logger.h"
#include <iostream>

int main(int argc, char* argv[]) {

  logging::LogMessage().Get(logging::LogLevel::Error) << "Error test";
  logging::LogMessage().Get(logging::LogLevel::Warning) << "Warning test";
  logging::LogMessage().Get(logging::LogLevel::Info) << "Info test";
  logging::LogMessage().Get(logging::LogLevel::Debug) << "Debug test";

}