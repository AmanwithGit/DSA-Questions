// LeetCode 52
class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;

        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                ans++;
                return;
            }

            for (int c = 0; c < n; c++) {
                if (col[c] || diag1[row - c + n - 1] ||
                    diag2[row + c])
                    continue;

                col[c] = true;
                diag1[row - c + n - 1] = true;
                diag2[row + c] = true;

                backtrack(row + 1);

                col[c] = false;
                diag1[row - c + n - 1] = false;
                diag2[row + c] = false;
            }
        };

        backtrack(0);
        return ans;
    }
};