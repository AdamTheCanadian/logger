# C++ Logger

Simple header only logger class for me to use in various projects. 

Was tired of always wishing I had logging functionality. Now I have a consistent logger that I can use, modify, and improve across all my projects.

Design/Implementation was inspired by 
https://www.drdobbs.com/cpp/logging-in-c/201804215?pgno=1

Some changes were made.
Use C++14 features like:
- scoped enum
- atomics
- c++ std::thread/mutex

Added a CMakeLists to the project so it can be used in other CMake projects.