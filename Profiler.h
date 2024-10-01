#ifndef PROFILER_H
#define PROFILER_H
#include <iostream>
#include <chrono>
#include <initializer_list>
#include <string>
#include <functional>

class Profiler {

  public:
  void profile(int runs, std::function<int (int)> func, int arg);

};

#endif
