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

bool solve(bool* board, int n, int row, std::vector<std::string>& answer, std::vector<std::vector<std::string>>& answers) {
  if (row == n) {
    answers.push_back(answer);
    return true;
  }

  for (int i = 0; i < n; i++) {
    if (*((board + (row)*n) + (i)) == 0) {
      if (checkBoard((bool*)board, row, i, n) == true) {
        *((board + (row) * n) + (i)) = 1;
        answer[row][i] = 'Q';
        solve((bool*)board, n, row + 1, answer, answers);
        *((board + (row)*n) + (i)) = 0;
        answer[row][i] = '.';
      }
    }    
  }
  return false;
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
  bool board[n][n];
  std::memset(board, 0, sizeof board);

  std::string row;
  row.reserve(n);
  for (int i = 0; i < n; i++) {
    row += '.';
  }
  std::vector<std::string> answer(n, row);

  std::vector<std::vector<std::string>> answers;
  answers.reserve(2 * n);
  solve((bool*)board, n, 0, answer, answers);

  return answers;
}

void printBoards(bool* board, int n, std::vector<std::string>& answer) {
  int(*b)[n][n] = (int(*)[n][n])board;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << (*b)[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
  for (auto row : answer) {
    std::cout << row << '\n';
  }

  std::cout << '\n';
  std::cin.get();
}

int main() {
  std::vector<std::vector<std::string>> answers = solveNQueens(4);
  for (auto vec:answers) {
    for (auto str:vec) {
      std::cout << str << '\n';
    }
    std::cout << '\n';
  }
}

// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     if ((*b)[i][j] == false) {
//       if (checkBoard((bool*)board, i, j, n) == true) {
//         updateBoard((bool*)board, i, j, n);
//         answer[i][j] = 'Q';
//         //pieces--;
//         std::cout << "placed" << '\n';
//         //pieces--;

//         std::cout << "PIECES: " << pieces << '\n';
//         for (int i = 0; i < n; i++) {
//           for (int j = 0; j < n; j++) {
//             std::cout << (*b)[i][j] << ' ';
//           }
//           std::cout << '\n';
//           }
//         std::cout << '\n';

//         for (auto row : answer) {
//           std::cout << row << '\n';
//         }
//         std::cout << '\n';
//         //std::cin.get();
//         (solve((bool*)board, n, pieces - 1, answer, answers) && pieces == 1);
//           //std::cout << "TEST\n";
//           //answers.push_back(answer);
//           //return true;
//         // } else {
//           // std::cout << "removed 1, i: " << i << ", j:" << j << "\n";
//           undoBoard((bool*)board, i, j, n);
//           //pieces++;
//           answer[i][j] = '.';
//           // for (int i = 0; i < n; i++) {
//           //   for (int j = 0; j < n; j++) {
//           //     std::cout << (*b)[i][j] << ' ';
//           //   }
//           //   std::cout << '\n';
//           // }
//           // std::cout << '\n';

//           // for (auto row : answer) {
//           //   std::cout << row << '\n';
//           // }
//           // std::cout << '\n';
//         //}
//         }

//       // std::memset(board, 0, sizeof board);
//       // pieces = 4;

//       // std::cout << "removed 2, i: " << i << ", j:" << j << "\n";
//       // for (int i = 0; i < n; i++) {
//       //   for (int j = 0; j < n; j++) {
//       //     std::cout << (*b)[i][j] << ' ';
//       //   }
//       //   std::cout << '\n';
//       // }
//       // std::cout << '\n';

//       // for (auto row : answer) {
//       //   std::cout << row << '\n';
//       // }
//       // std::cout << '\n';
//       // std::cin.get();

//     }
//     // undoBoard((bool*)board, i, j, n);
//     // pieces++;
//   }

// }
// // if (pieces == 0) {
// //   //answers.push_back(answer);
// //   return true;
// // }
// //answers.push_back(answer);
// return true;

// checkBoard((bool*)board, 0, 0, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';
// checkBoard((bool*)board, 1, 2, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';
// checkBoard((bool*)board, 3, 1, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';
// undoBoard((bool*)board, 3, 1, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';
// undoBoard((bool*)board, 1, 2, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';
// undoBoard((bool*)board, 0, 0, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';