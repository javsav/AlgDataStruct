#include <vector>
#include <iostream>
#include <bits/stdc++.h>

bool checkBoard(void* board, int r, int c, int n) {
  int(*b)[n][n] = (int(*)[n][n])board;

  if ((*b)[r][c] == true) {
    return false;
  }

  // Check row
  for (int i = 0; i < n; i++) {
    if (i == r) {
      continue;
    }
    if ((*b)[i][c] == true) {
      return false;
    }
  }
  // Check column
  for (int i = 0; i < n; i++) {
    if (i == c) {
      continue;
    }
    if ((*b)[r][i] == true) {
      return false;
    }
  }

  // Check DDR
  for (int i = 1; i + r < n && c + i < n; i++) {
    if ((*b)[i + r][c + i] == true) {
      return false;
    }
  }

  // Check DDL
  for (int i = 1; i + r < n && c - i >= 0; i++) {
    if ((*b)[i + r][c + i] == true) {
      return false;
    }
  }

  // Check DUR
  for (int i = 1; r - i >= 0 && c + i < n; i++) {
    if ((*b)[r - i][c + i] == true) {
      return false;
    }
  }

  // Check DUL
  for (int i = 1; r - i >= 0 && c - i >= 0; i++) {
    if ((*b)[r - i][c - i] == true) {
      return false;
    }
  }

  return true;
}

bool updateBoard(void* board, int r, int c, int n) {
  int(*b)[n][n] = (int(*)[n][n])board;

  if ((*b)[r][c] == true) {
    return false;
  } else {
    (*b)[r][c] = true;
  }

  // Check row
  for (int i = 0; i < n; i++) {
    if (i == r) {
      continue;
    }
    if ((*b)[i][c] == true) {
      return false;
    } else {
      (*b)[i][c] = 2;
    }
  }
  // Check column
  for (int i = 0; i < n; i++) {
    if (i == c) {
      continue;
    }
    if ((*b)[r][i] == true) {
      return false;
    } else {
      (*b)[r][i] = 2;
    }
  }

  // Check DDR
  for (int i = 1; i + r < n && c + i < n; i++) {
    if ((*b)[i + r][c + i] == true) {
      return false;
    } else {
      (*b)[i + r][c + i] = 2;
    }
  }

  // Check DDL
  for (int i = 1; i + r < n && c - i >= 0; i++) {
    if ((*b)[i + r][c + i] == true) {
      return false;
    } else {
      (*b)[i + r][c - i] = 2;
    }
  }

  // Check DUR
  for (int i = 1; r - i >= 0 && c + i < n; i++) {
    if ((*b)[r - i][c + i] == true) {
      return false;
    } else {
      (*b)[r - i][c + i] = 2;
    }
  }

  // Check DUL
  for (int i = 1; r - i >= 0 && c - i >= 0; i++) {
    if ((*b)[r - i][c - i] == true) {
      return false;
    } else {
      (*b)[r - i][c - i] = 2;
    }
  }

  return true;
}

bool undoBoard(void* board, int r, int c, int n) {
  int(*b)[n][n] = (int(*)[n][n])board;
  // Check row
  (*b)[r][c] = 0;
  for (int i = 0; i < n; i++) {
    if (i == r) {
      continue;
    }
    if (!checkBoard((*b), i, c, n)) {
      continue;
    } else {
      (*b)[i][c] = 0;
    }
  }
  // Check column
  for (int i = 0; i < n; i++) {
    if (i == c) {
      continue;
    }
    if (!checkBoard((*b), r, i, n)) {
      continue;
    } else {
      (*b)[r][i] = 0;
    }
  }

  // Check DDR
  for (int i = 1; i + r < n && c + i < n; i++) {
    if (!checkBoard((*b), i + r, c + i, n)) {
      continue;
    } else {
      (*b)[i + r][c + i] = 0;
    }
  }

  // Check DDL
  for (int i = 1; i + r < n && c - i >= 0; i++) {
    if (!checkBoard((*b), i + r, c - i, n)) {
      continue;
    } else {
      (*b)[i + r][c - i] = 0;
    }
  }

  // Check DUR
  for (int i = 1; r - i >= 0 && c + i < n; i++) {
    if (!checkBoard((*b), r - i, c + i, n)) {
      continue;
    } else {
      (*b)[r - i][c + i] = 0;
    }
  }

  // Check DUL
  for (int i = 1; r - i >= 0 && c - i >= 0; i++) {
    if (!checkBoard((*b), r - i, c - i, n)) {
      continue;
    } else {
      (*b)[r - i][c - i] = 0;
    }
  }

  return true;
}

bool solve(void* board, int n, int row, std::vector<std::string>& answer, std::vector<std::vector<std::string>>& answers) {
  int(*b)[n][n] = (int(*)[n][n])board;
  if (row == n) {
    answers.push_back(answer);
    return true;
  }

  for (int i = 0; i < n; i++) {
    if ((*b)[row][i] == 0) {
      if (checkBoard((*b), row, i, n) == true) {
        updateBoard((*b), row, i, n);
        answer[row][i] = 'Q';        
        solve((*b), n, row + 1, answer, answers);
        undoBoard((*b), row, i, n);
        answer[row][i] = '.';        
      }
    }
  }
  return false;
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
  int board[n][n];
  int (*b)[n][n] = (int(*)[n][n])board;
  std::memset(board, 0, sizeof board);
  int pieces = n;

  std::string row;
  row.reserve(n);
  for (int i = 0; i < n; i++) {
    row += '.';
  }
  std::vector<std::string> answer (n, row);

  std::vector<std::vector<std::string>> answers (n);
  solve((*b), n, 0, answer, answers);

  return answers;
}

void printBoards(void* board, int n, std::vector<std::string>& answer) {
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
}

int main() {
  solveNQueens(5);
}

// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     if ((*b)[i][j] == false) {
//       if (checkBoard((*b), i, j, n) == true) {
//         updateBoard((*b), i, j, n);
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
//         (solve((*b), n, pieces - 1, answer, answers) && pieces == 1);
//           //std::cout << "TEST\n";
//           //answers.push_back(answer);
//           //return true;
//         // } else {
//           // std::cout << "removed 1, i: " << i << ", j:" << j << "\n";
//           undoBoard((*b), i, j, n);
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
//     // undoBoard((*b), i, j, n);
//     // pieces++;
//   }

// }
// // if (pieces == 0) {
// //   //answers.push_back(answer);
// //   return true;
// // }
// //answers.push_back(answer);
// return true;

// checkBoard((*b), 0, 0, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';
// checkBoard((*b), 1, 2, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';
// checkBoard((*b), 3, 1, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';
// undoBoard((*b), 3, 1, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';
// undoBoard((*b), 1, 2, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';
// undoBoard((*b), 0, 0, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';