#include <bits/stdc++.h>

#include <iostream>
#include <vector>

bool checkBoard(int* board, int r, int c, int n) {
   if (*((board + (r) * n) + (c)) == true) {
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
    if (*((board + (i+r)*n) + (c+i)) == true) {
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
    if (*((board + (r-i) * n) + (c + i)) == true) {
      return false;
    }
  }

  // Check DUL
  for (int i = 1; r - i >= 0 && c - i >= 0; i++) {
    if (*((board + (r-i) * n) + (c-i)) == true) {
      return false;
    }
  }

  return true;
}

bool updateBoard(int* board, int r, int c, int n) { 

  if (*((board + (r)*n) + (c)) == true) {    
    return false;
  } else {
    *((board + (r)*n) + (c)) = true;
  }

  // Check row
  for (int i = 0; i < n; i++) {
    if (i == r) {
      continue;
    }
    if (*((board + (i)*n) + (c)) == true) {
      return false;
    } else {
      *((board + (i)*n) + (c)) = 2;
    }
  }
  // Check column
  for (int i = 0; i < n; i++) {
    if (i == c) {
      continue;
    }
    if (*((board + (r)*n) + (i)) == true) {
      return false;
    } else {
      *((board + (r)*n) + (i)) = 2;
    }
  }

  // Check DDR
  for (int i = 1; i + r < n && c + i < n; i++) {
    if (*((board + (i+r)*n) + (c+i)) == true) {
      return false;
    } else {
      *((board + (i + r) * n) + (c + i)) = 2;
    }
  }

  // Check DDL
  for (int i = 1; i + r < n && c - i >= 0; i++) {
    if (*((board + (i + r) * n) + (c - i)) == true) {
      return false;
    } else {
      *((board + (i + r) * n) + (c - i)) = 2;
    }
  }

  // Check DUR
  for (int i = 1; r - i >= 0 && c + i < n; i++) {
    if (*((board + (r -i) * n) + (c + i)) == true) {
      return false;
    } else {
      *((board + (r - i) * n) + (c + i)) = 2;
    }
  }

  // Check DUL
  for (int i = 1; r - i >= 0 && c - i >= 0; i++) {
    if (*((board + (r - i) * n) + (c - i)) == true) {
      return false;
    } else {
      *((board + (r - i) * n) + (c - i)) = 2;
    }
  }

  return true;
}

bool undoBoard(int* board, int r, int c, int n) {
  // Check row
  *((board + r * n) + c) = 0;
  for (int i = 0; i < n; i++) {
    if (i == r) {
      continue;
    }
    // if (!checkBoard((int*)board, i, c, n)) {
    //   continue;
    // } else {
      *((board + i * n) + c) = 0;
    //}
  }
  // Check column
  for (int i = 0; i < n; i++) {
    if (i == c) {
      continue;
    }
    // if (!checkBoard((int*)board, r, i, n)) {
    //   continue;
    // } else {
      *((board + r * n) + i) = 0;
    //}
  }

  // Check DDR
  for (int i = 1; i + r < n && c + i < n; i++) {
    // if (!checkBoard((int*)board, i + r, c + i, n)) {
    //   continue;
    // } else {
      *((board + (i + r) * n) + (c + i)) = 0;      
   // }
  }

  // Check DDL
  for (int i = 1; i + r < n && c - i >= 0; i++) {
    // if (!checkBoard((int*)board, i + r, c - i, n)) {
    //   continue;
    // } else {
      *((board + (i+r) * n) + (c-i)) = 0;      
    //}
  }

  // Check DUR
  for (int i = 1; r - i >= 0 && c + i < n; i++) {
    // if (!checkBoard((int*)board, r - i, c + i, n)) {
    //   continue;
    // } else {
      *((board + (r - i) * n) + (c + i)) = 0;
    //}
  }

  // Check DUL
  for (int i = 1; r - i >= 0 && c - i >= 0; i++) {
    // if (!checkBoard((int*)board, r - i, c - i, n)) {
    //   continue;
    // } else {
      *((board + (r - i) * n) + (c - i)) = 0;
    //}
  }

  return true;
}

void printBoards(int* board, int n, std::vector<std::string>& answer) {
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

bool solve(int* board, int n, int row, std::vector<std::string>& answer, std::vector<std::vector<std::string>>& answers, std::vector<std::pair<int, int>> positions) {
  
  if (row == n) {
    answers.push_back(answer);
    return true;
  }

  for (int i = 0; i < n; i++) {
    if (*((board + row * n) + i) == 0) {
      if (checkBoard((int*)board, row, i, n) == true) {
        updateBoard((int*)board, row, i, n);
        answer[row][i] = 'Q';
        positions.emplace_back(row, i);
        solve((int*)board, n, row + 1, answer, answers, positions);
        positions.pop_back();
        undoBoard((int*)board, row, i, n);
        for (auto pos:positions) {          
          updateBoard((int*)board, pos.first, pos.second, n);
        }
        answer[row][i] = '.';
      }
    }
  }
  return false;
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
  int board[n][n]; 
  std::memset(board, 0, sizeof board);

  std::string row;
  row.reserve(n);
  for (int i = 0; i < n; i++) {
    row += '.';
  }
  std::vector<std::string> answer(n, row);
  std::vector<std::pair<int, int>> positions;
  positions.reserve(n*n);
  std::vector<std::vector<std::string>> answers;
  answers.reserve(n);
  solve((int*)board, n, 0, answer, answers, positions);

  return answers;
}



// int main() {
//   std::vector<std::vector<std::string>> answers = solveNQueens(4);
//   for (auto vec:answers) {
//     for (auto str:vec) {
//       std::cout << str << '\n';
//     }
//     std::cout << '\n';
//   }
// }

// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     if ((*b)[i][j] == false) {
//       if (checkBoard((int*)board, i, j, n) == true) {
//         updateBoard((int*)board, i, j, n);
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
//         (solve((int*)board, n, pieces - 1, answer, answers) && pieces == 1);
//           //std::cout << "TEST\n";
//           //answers.push_back(answer);
//           //return true;
//         // } else {
//           // std::cout << "removed 1, i: " << i << ", j:" << j << "\n";
//           undoBoard((int*)board, i, j, n);
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
//     // undoBoard((int*)board, i, j, n);
//     // pieces++;
//   }

// }
// // if (pieces == 0) {
// //   //answers.push_back(answer);
// //   return true;
// // }
// //answers.push_back(answer);
// return true;

// checkBoard((int*)board, 0, 0, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';
// checkBoard((int*)board, 1, 2, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';
// checkBoard((int*)board, 3, 1, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';
// undoBoard((int*)board, 3, 1, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';
// undoBoard((int*)board, 1, 2, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';
// undoBoard((int*)board, 0, 0, n);
// for (int i = 0; i < n; i++) {
//   for (int j = 0; j < n; j++) {
//     std::cout << (*b)[i][j] << ' ';
//   }
//   std::cout << '\n';
// }
// std::cout << '\n';