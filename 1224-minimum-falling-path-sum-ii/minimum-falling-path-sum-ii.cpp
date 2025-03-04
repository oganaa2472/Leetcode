class Solution {
public:
    vector<vector<int>> memo;
    int n;

    int solve(vector<vector<int>>& matrix, int i, int j) {
        if (j < 0 || j >= n) return INT_MAX; 
        if (i == n - 1) return matrix[i][j]; 
        if (memo[i][j] != INT_MAX) return memo[i][j]; 

        int min_value = INT_MAX;
        for (int k = 0; k < n; k++) {
            if (j != k) { 
                min_value = min(min_value, solve(matrix, i + 1, k));
            }
        }

        return memo[i][j] = matrix[i][j] + min_value;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        memo.assign(n, vector<int>(n, INT_MAX)); 
        int minSum = INT_MAX;

        for (int j = 0; j < n; j++) {
            minSum = min(minSum, solve(matrix, 0, j));
        }
        return minSum;
    }
};
