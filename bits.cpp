#include <iostream>
#include <bitset>
#include <cstddef>
#include <array>
#include <vector>

template <class T, int m, int n>
class matrix {
  private:
   std::array<T, m * n> data{{}};   

  public:
  size_t rows = m;
  size_t cols = n;
  matrix() {

  }
  T& operator()(int r, int c) {
    return data[r*n + c];
  }
  T& operator[](int pos) {
    return data[pos];
  }  

};

bool isValidSudoku(std::vector<std::vector<char>>& board) {
  matrix<bool, 9, 9> rows;
  matrix<bool, 9, 9> cols;
  matrix<bool, 9, 9> squares;
  
  for (int r = 0; r < board.size(); r++) {
    for (int c = 0; c < board[0].size(); c++) {
      if (board[r][c] != '.') {
        if (rows(r, board[r][c] - '0' - 1) == true) {          
          return false;
        } else {
          rows(r, board[r][c] - '0' - 1) = true;
        }
        if (cols(c, board[r][c] - '0' - 1) == true) {
          return false;
        } else {
          cols(c, board[r][c] - '0' - 1) = true;
        }
        if (squares((c / 3 + ((r / 3) * 3)), board[r][c] - '0' - 1) == true) {
          return false;
        } else {
          squares((c / 3 + ((r / 3) * 3)), board[r][c] - '0' - 1) = true;
        }
      }
    }
  }
  return true;
}

int main() {
  std::vector<std::vector<char>> board = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' }, { '6', '.', '.', '1', '9', '5', '.', '.', '.' }, { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, { '8', '.', '.', '.', '6', '.', '.', '.', '3' }, { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, { '7', '.', '.', '.', '2', '.', '.', '.', '6' }, { '.', '6', '.', '.', '.', '.', '2', '8', '.' }, { '.', '.', '.', '4', '1', '9', '.', '.', '5' }, { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
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