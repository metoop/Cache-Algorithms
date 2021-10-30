class Solution {
  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < int > rowPos(n, -1);
      vector < int > colPos(n, -1);
      vector < vector < string >> boards;

      backtracking(n, 0, rowPos, colPos, boards);
      return boards;
    }

  void backtracking(int n, int from, vector < int > & rowPos, vector < int > & colPos,
    vector < vector < string >> & boards) {
    if (from == n) {
      vector < string > board(n, string(n, '.'));
      for (int row = 0; row < n; row++) {
        int col = rowPos[row];
        board[row][col] = 'Q';
      }
      boards.push_back(board);
      return;
    }
    for (int col = 0; col < n; col++) {
      bool valid = isValid(n, from, col, rowPos, colPos);
      if (valid) {
        rowPos[from] = col;
        colPos[col] = from;
        backtracking(n, from + 1, rowPos, colPos, boards);
        rowPos[from] = -1;
        colPos[col] = -1;
      }
    }
  }

  bool isValid(int n, int row, int col, vector < int > & rowPos, vector < int > & colPos) {
    if (rowPos[row] != -1)
      return false;
    if (colPos[col] != -1)
      return false;
    int tmpRow = row;
    int tmpCol = col;
    while (true) {
      tmpRow++;
      tmpCol++;

      if (tmpRow == n || tmpCol == n) break;
      if (rowPos[tmpRow] == tmpCol) return false;
    }
    tmpRow = row;
    tmpCol = col;
    while (true) {
      tmpRow--;
      tmpCol--;

      if (tmpRow < 0 || tmpCol < 0) break;
      if (rowPos[tmpRow] == tmpCol) return false;
    }
    tmpRow = row;
    tmpCol = col;
    while (true) {
      tmpRow++;
      tmpCol--;

      if (tmpRow == n || tmpCol < 0) break;
      if (rowPos[tmpRow] == tmpCol) return false;
    }
    tmpRow = row;
    tmpCol = col;
    while (true) {
      tmpRow--;
      tmpCol++;

      if (tmpRow < 0 || tmpCol == n) break;
      if (rowPos[tmpRow] == tmpCol) return false;
    }
    return true;
  }
};
//
