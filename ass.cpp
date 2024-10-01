#include <array>
#include <bitset>
#include <cstddef>
#include <iostream>
#include <vector>

// template <class T, int m, int n>
// class matrix {
//  private:
//   std::array<T, m * n> data{{}};

//  public:
//   size_t rows = m;
//   size_t cols = n;
//   matrix() {
//   }
//   T operator()(int r, int c) {
//     return data[r * n + c];
//   }
//   T& operator[](int pos) {
//     return data[pos];
//   }

//   void set(int r, int c, T val) {
//     data[r * n + c] = val;
//   }
// };

bool isValidSudoku(std::vector<std::vector<char>>& board) {
  bool rows[9*9] = {false};
  bool cols[9*9] = {false};
  bool squares[11*11] = {false};

  for (int r = 0; r < board.size(); r++) {
    for (int c = 0; c < board[0].size(); c++) {
      if (board[r][c] != '.') {
        if (rows[r * 9 + (board[r][c] - 1)] == true) {
          return false;
        } else {
          rows[r * 9 + (board[r][c] - 1)] = true;
        }
        std::cout << "c: " << c << "\n";
        std::cout << "boardval: " << (board[r][c]) << "\n";
        std::cout << "calc: " << c * 9 + (board[r][c] - 1) << "\n";
        if (cols[c * 9 + (board[r][c] - 1)] == true) {
          return false;
        } else {
          cols[c * 9 + (board[r][c] - 1)] = true;
        }
        if (squares[((c / 3 + ((r / 3) * 3)) * 9) + board[r][c] - 1] == true) {
          return false;
        } else {
          squares[((c / 3 + ((r / 3) * 3)) * 9) + board[r][c] - 1] = true;
        }
      }
    }
  }
  return true;
}

int main() {
  std::vector<std::vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  std::cout << isValidSudoku(board) << "\n";

  // matrix<int, 9, 9> test;

  // for (int i = 0; i < 9; i++) {
  //   for (int j = 0; j < 9; j++) {
  //     test(i, j) = i + j;
  //   }
  // }

  // for (int i = 0; i < 9; i++) {
  //   for (int j = 0; j < 9; j++) {
  //     std::cout << test(i, j) << " ";
  //   }
  //   std::cout << "\n";
  // }
  // // for (int i = 81; i < 100; i++) {
  // //   std::cout << test[i] << " ";
  // // }
  // std::cout << test[80];
}