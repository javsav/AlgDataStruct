#include <vector>
#include <iostream>
#include <unordered_set>

    bool isValidSudoku(std::vector<std::vector<char>>& board) {

      std::unordered_set<char> digits = {{'1', '2', '3', '4', '5', '6', '7', '8', '9'}};
      std::unordered_set<char> horizontalSet;
      std::unordered_set<char> verticalSet;
      std::unordered_set<char> squareSetOne;
      std::unordered_set<char> squareSetTwo;
      std::unordered_set<char> squareSetThree;

      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          if (i != 0 && i % 3 == 0 && j == 0) {
            squareSetOne.clear();
            squareSetTwo.clear();
            squareSetThree.clear();
          }
          if (board[i][j] != '.') {
          if (digits.count(board[i][j])) {
            if (horizontalSet.count(board[i][j])) {
              return false;
            } else {
              horizontalSet.insert(board[i][j]);
            }

            if (j <= 2) {
              if (squareSetOne.count(board[i][j])) {
                return false;
              } else {
                squareSetOne.insert(board[i][j]);
              }
            } else if (j <= 5) {
              if (squareSetTwo.count(board[i][j])) {
                return false;
              } else {
                squareSetTwo.insert(board[i][j]);
              }
            } else {
              if (squareSetThree.count(board[i][j])) {
                return false;
              } else {
                squareSetThree.insert(board[i][j]);
              }
            }
          } else {
            return false;
          }
          }
          if (board[j][i] != '.') {
          if (verticalSet.count(board[j][i])) {
            return false;
          } else {
            verticalSet.insert(board[j][i]);
          }
          }
        }
        verticalSet.clear();
        horizontalSet.clear();
      }

    return true;
    }

    int main() {

      std::vector<std::vector<char>> board =
      {{'5','3','.','.','7','.','.','.','.'}
      ,{'6','.','.','1','9','5','.','.','.'}
      ,{'.','9','8','.','.','.','.','6','.'}
      ,{'8','7','.','.','6','.','.','.','3'}
      ,{'4','.','.','8','.','3','.','.','1'}
      ,{'7','.','.','.','2','.','.','.','6'}
      ,{'.','6','.','.','.','.','2','8','.'}
      ,{'.','.','.','4','1','9','.','.','5'}
      ,{'.','.','.','.','8','.','.','7','9'}};

      std::cout << isValidSudoku(board) << "\n";
    }
