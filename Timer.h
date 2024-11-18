#include <chrono>
#include <iostream>
#include <vector>
class Timer {
 private:
  std::chrono::_V2::high_resolution_clock::time_point m_startTime;
  std::chrono::_V2::high_resolution_clock::time_point m_endTime;
  std::chrono::milliseconds m_elapsedTime;

 public:
  void startTimer();
  void stopTimer();
  std::chrono::milliseconds time();
};