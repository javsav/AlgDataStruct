#include <queue>
#include <vector>

int kth_largest(std::vector<int> values, int k) {
  std::priority_queue<int> pqueue;

  for (auto num:values) {
    pqueue.push(num);
  }

  while (k > 1 && !pqueue.empty()) {
    pqueue.pop();
    k--;
  }

  return pqueue.top();
}