#include <bits/stdc++.h>

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
  int n = matrix.size();
  int m = matrix[0].size();

  std::vector<int> answer;
  answer.reserve(n * m);

  if (n == 1) {
    return matrix[0];
  } else if (m == 1) {
    for (int i = 0; i < n; i++) {
      answer.push_back(matrix[i][0]);
    }
    return answer;
  }

  int topRight = m - 1;
  int bottomRight = n - 1;
  int bottomLeft = 0;
  int topLeft = 1;

  
  int ptrRow = 0;
  int ptrCol = 0;
  int count = 0;  

  while ((count < m*n)) {
    while ((ptrCol < topRight)) {
      answer.push_back(matrix[ptrRow][ptrCol]);
      ptrCol++;
      count++;
    }
    topRight--;

    if (count == m*n - 1) {
      break;
    }
    
    while ((ptrRow < bottomRight)) {
      answer.push_back(matrix[ptrRow][ptrCol]);
      ptrRow++;
      count++;
    }

    bottomRight--;

    while ((ptrCol > bottomLeft)) {
      answer.push_back(matrix[ptrRow][ptrCol]);
      ptrCol--;
      count++;
    }

    bottomLeft++;
    

    while ((ptrRow > topLeft)) {
      answer.push_back(matrix[ptrRow][ptrCol]);
      ptrRow--;
      count++;
    }

    topLeft++;

    if (count == m*n - 1) {
      break;
    }
  }
  answer.push_back(matrix[ptrRow][ptrCol]);
  
  return answer;

}



std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
  for (auto vec = intervals.begin(); vec < intervals.end() - 1; ++vec) {
    bool erase = false;
    auto next = vec + 1;
    if ((*vec)[1] > (*next)[1] && (*vec)[0] == (*next)[1]) {
      (*vec)[0] = (*next)[0];
      erase = true;
    }
    else if ((*vec)[1] > (*next)[1] && (*vec)[0] > (*next)[0]) {
      continue;
    }
    
    else if ((*vec)[1] >= (*next)[0] && (*vec)[0] <= (*next)[0] && (*vec)[1] <= (*next)[1]) {
      (*vec)[1] = (*next)[1];
      erase = true;
    } else if ((*vec)[1] >= (*next)[1] && (*vec)[0] <= (*next)[0]) {
      erase = true;
    } else if ((*vec)[0] > (*next)[0]) {
      (*vec)[0] = (*next)[0];
      erase = true;
      if ((*vec)[1] < (*next)[1]) {
        (*vec)[1] = (*next)[1];
      }
    }

    if (erase) {
      intervals.erase(next);
    }
  }

  return intervals;
}

  // int main() {
  //   std::vector<std::vector<int>> sp = {{1,4},{2,3}};

  //   merge(sp);

  //   for (auto vec:sp) {
  //   for (int n:vec) {
  //     std::cout << n << ' ';
  //   }
  //   std::cout << '\n';}



  // }

class Animal {
 public:
  virtual void makeSound() {
    std::cout << "";
  }
};
class Tiger : public Animal {
 public:
  void makeSound() {
    std::cout << "Roar";
  }
};
int main(void) {
  Animal* zoo[10];
  int zooSize = 0;
  Tiger* tigger = new Tiger;
  //tigger.makeSound();
  zoo[zooSize] = tigger;
  //zoo[0].makeSound();
  zooSize++;
  for (int i = 0; i < zooSize; i++) {
    zoo[i]->makeSound();
  }
}
