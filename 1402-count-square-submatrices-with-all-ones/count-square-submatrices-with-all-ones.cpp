class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size(), count = 0;
    
    // Initialize the DP array with the same size as matrix
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            // If it's the first row or column, DP value is same as matrix cell
            if(i == 0 || j == 0) {
                dp[i][j] = matrix[i][j];
            }
            // Else calculate the dp value
            else if(matrix[i][j] == 1) {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
            // Increment count by the value in dp
            count += dp[i][j];
        }
    }
    
    return count;
}

};