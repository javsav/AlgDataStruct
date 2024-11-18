#include "Timer.h"

void Timer::startTimer() {
  m_startTime = std::chrono::high_resolution_clock::now();
}

void Timer::stopTimer() {
  m_endTime = std::chrono::high_resolution_clock::now();
  m_elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(m_endTime - m_startTime);
}

std::chrono::milliseconds Timer::time() {
  return m_elapsedTime;
}