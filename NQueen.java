class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        char[][] board = new char[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = '.';
            }
        }
        dfs(res, board, n, 0);
        return res;
    }
    
    private List<String> boardToRes(char[][] board) {
        List<String> res = new ArrayList<>();
        for (char[] row : board) {
            res.add(String.valueOf(row));
        }
        return res;
    }
    
    private void dfs(List<List<String>> res, char[][] board, int n, int r) {
        if (r >= n) {
            res.add(boardToRes(board));
            return;
        }
        for (int c = 0; c < n; ++c) {
            if (isValid(board, r, c, n)) {
                board[r][c] = 'Q';
                dfs(res, board, n, r + 1);
                board[r][c] = '.';
            }
        }
    }
    
    private boolean isValid(char[][] board, int r, int c, int n) {
        for (int i = 0; i != r; ++i) {
            if (board[i][c] == 'Q') {
                return false;
            }
        }
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
}
