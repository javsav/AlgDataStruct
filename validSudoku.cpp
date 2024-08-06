#include <vector>

bool isValidSudoku(std::vector<std::vector<char>> &board) {

  bool horizontal[9][9] = {false};
  bool vertical[9][9] = {false};
  bool square[9][9] = {false};

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {

      if (board[i][j] != '.') {
        int dig = board[i][j], s = ((i / 3) * 3 + j / 3);

        if (horizontal[i][dig] || vertical[j][dig] || square[s][dig]) {
          return false;
        }

        horizontal[i][dig] = vertical[j][dig] = square[s][dig] = 1;
      }
    }
  }

  return true;
}
