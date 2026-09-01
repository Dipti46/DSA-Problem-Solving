class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        function<void(int)> solve = [&](int row) {

            if (row == n) {
                ans.push_back(board);
                return;
            }

            for (int c = 0; c < n; c++) {

                if (col[c] || 
                    diag1[row - c + n - 1] || 
                    diag2[row + c])
                    continue;

                board[row][c] = 'Q';

                col[c] = true;
                diag1[row - c + n - 1] = true;
                diag2[row + c] = true;

                solve(row + 1);

                board[row][c] = '.';

                col[c] = false;
                diag1[row - c + n - 1] = false;
                diag2[row + c] = false;
            }
        };

        solve(0);

        return ans;
    }
};