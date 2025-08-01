class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,1));
        int mod = 1e9+7;
        for(int i = 1;i<=k;i++){
            for(int j = 1;j<n;j++){
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
        return dp[k][n-1];
    }
};