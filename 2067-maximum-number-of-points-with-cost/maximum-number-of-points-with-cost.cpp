class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();
        
        vector<long long> dp(cols, 0);
        
        // Initialize DP table with the first row values
        for (int j = 0; j < cols; j++) {
            dp[j] = points[0][j];
        }
        
        // Process row by row
        for (int i = 1; i < rows; i++) {
            // Compute the left and right maximum arrays
            vector<long long> left(cols, 0);
            vector<long long> right(cols, 0);
            
            left[0] = dp[0];
            for (int j = 1; j < cols; j++) {
                left[j] = max(left[j-1] - 1, dp[j]);
            }
            
            right[cols-1] = dp[cols-1];
            for (int j = cols-2; j >= 0; j--) {
                right[j] = max(right[j+1] - 1, dp[j]);
            }
            
            // Update the DP table with the max score for the current row
            for (int j = 0; j < cols; j++) {
                dp[j] = points[i][j] + max(left[j], right[j]);
            }
        }
        
        // Return the maximum score from the last row
        return *max_element(dp.begin(), dp.end());
    }
};