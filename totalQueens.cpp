#include <bits/stdc++.h>

#include <iostream>
#include <vector>

bool checkBoard(bool* board, int r, int c, int n) {
  if (*((board + (r)*n) + (c)) == true) {
    return false;
  }

  // Check row
  for (int i = 0; i < n; i++) {
    if (i == r) {
      continue;
    }
    if (*((board + (i)*n) + (c)) == true) {
      return false;
    }
  }
  // Check column
  for (int i = 0; i < n; i++) {
    if (i == c) {
      continue;
    }
    if (*((board + (r)*n) + (i)) == true) {
      return false;
    }
  }

  // Check DDR
  for (int i = 1; i + r < n && c + i < n; i++) {
    if (*((board + (i + r) * n) + (c + i)) == true) {
      return false;
    }
  }

  // Check DDL
  for (int i = 1; i + r < n && c - i >= 0; i++) {
    if (*((board + (i + r) * n) + (c - i)) == true) {
      return false;
    }
  }

  // Check DUR
  for (int i = 1; r - i >= 0 && c + i < n; i++) {
    if (*((board + (r - i) * n) + (c + i)) == true) {
      return false;
    }
  }

  // Check DUL
  for (int i = 1; r - i >= 0 && c - i >= 0; i++) {
    if (*((board + (r - i) * n) + (c - i)) == true) {
      return false;
    }
  }

  return true;
}

bool solve(bool* board, int n, int row, std::vector<std::string>& answer, int& answers) {
  if (row == n) {
    answers++;
    return true;
  }

  for (int i = 0; i < n; i++) {
    if (*((board + (row)*n) + (i)) == 0) {
      if (checkBoard((bool*)board, row, i, n) == true) {
        *((board + (row)*n) + (i)) = 1;
        answer[row][i] = 'Q';
        solve((bool*)board, n, row + 1, answer, answers);
        *((board + (row)*n) + (i)) = 0;
        answer[row][i] = '.';
      }
    }
  }
  return false;
}

int totalQueens(int n) {
  bool board[n][n];
  std::memset(board, 0, sizeof board);

  std::string row;
  row.reserve(n);
  for (int i = 0; i < n; i++) {
    row += '.';
  }
  std::vector<std::string> answer(n, row);

  int answers = 0;
  solve((bool*)board, n, 0, answer, answers);

  return answers;
}

// void printBoards(bool* board, int n, std::vector<std::string>& answer) {
//   int(*b)[n][n] = (int(*)[n][n])board;
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//       std::cout << (*b)[i][j] << ' ';
//     }
//     std::cout << '\n';
//   }
//   std::cout << '\n';
//   for (auto row : answer) {
//     std::cout << row << '\n';
//   }

//   std::cout << '\n';
//   std::cin.get();
// }

int main() {
  int answers = totalQueens(4);
  std::cout << answers << '\n';
  // for (auto vec : answers) {
  //   for (auto str : vec) {
  //     std::cout << str << '\n';
  //   }
  //   std::cout << '\n';
  // }
}