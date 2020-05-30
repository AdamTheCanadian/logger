#include "include/logger/logger.h"
#include <thread>
#include <iostream>

void LogLoop() {

  static const std::uint64_t num_iters = 1000000;
  for (std::uint64_t i = 0; i < num_iters; i++) {
    LOG_ERROR << "Thread: " << std::this_thread::get_id() << " on count " << i;
    // These messages should not appear since the logging level was set to info
    LOG_DEBUG << "Thread: " << std::this_thread::get_id() << " on count " << i;
  }
}

int main() {

  // Set the logging level of our application to INFO
  Log::LoggingLevel() = logging::LogLevel::Info;
  // Set the output to go to a file
  logging::LogToFile::LogStream() = fopen("example_log.txt", "w");
  
  // Want to measure the elapsed time, so start the timer before threads
  auto start = std::chrono::high_resolution_clock::now();

  // Create 10 threads to all execute the log loop
  std::thread all_threads[10];
  for (int i = 0; i < 10; i++) {
    all_threads[i] = std::thread(LogLoop);
  }

  for (int i = 0; i < 10; i++) {
    all_threads[i].join();
  }

  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "Total time (ms): " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << 
    std::endl;

}