class Solution {
public:
    int rows[9] = {};
    int cols[9] = {};
    int box[9] = {};
    vector<vector<char>> board;
    bool solved = false;

    bool isValid(int i, int j, int val) {
        int mask = (1 << val);
        return !(rows[i] & mask || cols[j] & mask || box[(i / 3) * 3 + (j / 3)] & mask);
    }

    void dfs(int i, int j) {
        if (i >= 9) {
            solved = true;
            return;
        }

        int newI = (j + 1 == 9) ? i + 1 : i;
        int newJ = (j + 1 == 9) ? 0 : j + 1;

        if (board[i][j] != '.') {
            dfs(newI, newJ);
        } else {
            for (char ch = '1'; ch <= '9'; ch++) {
                int val = ch - '1';
                if (isValid(i, j, val)) {
                    board[i][j] = ch;

                    rows[i] |= (1 << val);
                    cols[j] |= (1 << val);
                    box[(i / 3) * 3 + (j / 3)] |= (1 << val);

                    dfs(newI, newJ);
                    if (solved) return;

                    // Backtrack
                    board[i][j] = '.';
                    rows[i] &= ~(1 << val);
                    cols[j] &= ~(1 << val);
                    box[(i / 3) * 3 + (j / 3)] &= ~(1 << val);
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& inputBoard) {
        board = inputBoard;

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    int val = board[r][c] - '1';
                    rows[r] |= (1 << val);
                    cols[c] |= (1 << val);
                    box[(r / 3) * 3 + (c / 3)] |= (1 << val);
                }
            }
        }

        dfs(0, 0);
        inputBoard = board;
    }
};
