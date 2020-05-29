#ifndef __LOGGER_H
#define __LOGGER_H

#include <chrono>
#include <sstream>
#include <string>
#include <atomic>
#include <iomanip>
#include <ctime>
#include <cstdint>

namespace logging {

enum class LogLevel {
  Error,
  Warning,
  Info,
  Debug,
};

class LogMessage {

public:

  LogMessage();

  virtual ~LogMessage();

  std::ostringstream& Get(LogLevel level = LogLevel::Info);

  /**
   * @brief Returns a reference to the current logging level.
   * 
   * Can be used to change the logging level, or test against the 
   * current logging level
   * 
   * @return LogLevel& 
   */
  static LogLevel& LoggingLevel();

  /**
   * @brief Converts the enum log level into string format
   * 
   * @param level 
   * @return std::string 
   */
  static std::string LevelToString(LogLevel level);

protected:

  // Stream object that will be used to hold the log message
  std::ostringstream os;

private:

  // Make the copy constructor private to avoid copies of a log 
  // message (wouldnt really make sense)
  LogMessage(const LogMessage&);

  // Make the assignment operator private (same reason as copy constructor, 
  // does not make sense)
  LogMessage& operator = (const LogMessage&);

  LogLevel msg_level_;
}; // end of class LogMessage
} // end of namespace logging

logging::LogMessage::LogMessage() {

}

logging::LogMessage::~LogMessage() {

  os << std::endl;
  fprintf(stdout, "%s", os.str().c_str());
  fflush(stdout);
}

std::ostringstream& logging::LogMessage::Get(logging::LogLevel level) {

  using namespace std::chrono;
  // Get the current time, needed for the log message
  auto now = high_resolution_clock::now();
  auto now_t = high_resolution_clock::to_time_t(now);

  // Put the year/month/day hour:min:sec
  os << std::put_time(std::localtime(&now_t), "%x %T");
  // We want millisecond resolution in the log, so need to add the milli
  // seconds to the log. First put the decimal after the seconds, and 
  // want to always have three decimal places
  os << "." << std::setfill('0') << std::setw(3);
  os << (duration_cast<milliseconds>(now.time_since_epoch()) % 1000).count() << " ";
  // Set a constant width between the end of the ': ' and the message. 12 was found
  // from trial and error
  os << LevelToString(level) << ": " << std::setfill(' ') << std::setw(12);
  msg_level_ = level;
  return os;
}

logging::LogLevel& logging::LogMessage::LoggingLevel() {
  static logging::LogLevel level = logging::LogLevel::Debug;
  return level;
}

std::string logging::LogMessage::LevelToString(LogLevel level) {

  switch(level) {
  case LogLevel::Error: return "ERROR";
  case LogLevel::Warning: return "WARNING";
  case LogLevel::Info: return "INFO";
  case LogLevel::Debug: return "DEBUG";
  // Default case should only happen if a new logging level was added, and
  // the case was not added in this function
  default: 
    LogMessage().Get(LogLevel::Info) << "Unknown logging level. Resorting to INFO level";
    return "INFO";
  }
}

/* Macro for log messages. This is used so the check if the desired log 
* level (level) is above the set logging level is now here, and not in
* the destructor of the LogMessage object. AKA should be faster 
* Example: LOG(LogLevel::Error) << "Error " << 123.45;
* Expands to: 
* if (LogLevel::Error > logging::LogMessage::LoggingLevel()) {
*   // do nothing
* }
* else {
* // (...) is the standard logging header: time + level
*  ... << "Error " <<  123.45;
* }
*/
#define LOG(level) \
  if (level > logging::LogMessage::LoggingLevel()) ; \
  else logging::LogMessage().Get(level)

#define LOG_DEBUG LOG(logging::LogLevel::Debug) 
#define LOG_INFO LOG(logging::LogLevel::Info) 
#define LOG_WARNING LOG(logging::LogLevel::Warning) 
#define LOG_ERROR LOG(logging::LogLevel::Error) 

#endif