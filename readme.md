# C++ Logger

Simple header only logger class for me to use in various projects. 

Was tired of always wishing I had logging functionality. Now I have a consistent logger that I can use, modify, and improve across all my projects.

Design/Implementation was inspired by 
https://www.drdobbs.com/cpp/logging-in-c/201804215?pgno=1

Some changes from the original were made:
- chrono for time information
- scoped enum
- atomics
- c++ std::thread/mutex
- Global namespace macro for each log level: `LOG_DEBUG << "my debug message;` vs `LOG(DEBUG) << "my debug message"`

Added a CMakeLists to the project so it can be used in other CMake projects.

## Examples

### main.cpp
Shows how to simply set logging level, write log messages using two different provided macros, and how to set logs to go to a file.

### log_threading_example.cpp
Create 10 threads, and each thread output an Error and debug log message 1 million times, and time the execution.

On my PC it took ~60 seconds to complete. Not sure if that is good or not.

**One thing I did notice in this example is the log messages in the file can appear out of order in time, will have later messages appear before earlier messages**. I need to look into if this is a symptom of something greater or is just a limitation of the logger and may not be a big deal (depending on the use case). 