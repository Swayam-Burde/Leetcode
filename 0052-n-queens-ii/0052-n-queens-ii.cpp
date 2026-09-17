class Solution {
public:
    int solve(int row, int n, vector<bool>& cols, vector<bool>& diag, vector<bool>& non_diag) {
        if (row == n) {
            return 1;
        }
        int count = 0;
        for (int col = 0; col < n; col++) {
            int d_idx = row - col + n - 1; 
            int n_idx = row + col;
            if (cols[col] || diag[d_idx] || non_diag[n_idx]) {
                continue; 
            }
            cols[col] = true;
            diag[d_idx] = true;
            non_diag[n_idx] = true;
            count += solve(row + 1, n, cols, diag, non_diag);
            cols[col] = false;
            diag[d_idx] = false;
            non_diag[n_idx] = false;
        }
        return count;
    }
    int totalNQueens(int n) {
        vector<bool> cols(n, false);
        vector<bool> diagonals(2 * n - 1, false);
        vector<bool> non_diagonals(2 * n - 1, false);
        return solve(0, n, cols, diagonals, non_diagonals);
    }
};