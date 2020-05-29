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