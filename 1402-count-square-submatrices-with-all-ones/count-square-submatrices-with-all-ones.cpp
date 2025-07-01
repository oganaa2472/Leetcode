class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        vector<vector<int>>  dp((n),vector<int>(m));

        for(int i =0;i<m;i++){
            dp[0][i] = matrix[0][i];
            count += matrix[0][i];
        }
        for(int i =1;i<n;i++){
            dp[i][0] = matrix[i][0];
            count += matrix[i][0];
        }
        for(int i = 1;i<n;++i){
            for(int j = 1;j<m;++j){
                if(matrix[i][j]==1)
                    dp[i][j] = 1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                count += dp[i][j];
            } 
        }
        return count;
    }
};