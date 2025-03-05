class Solution {
public:
    int mod = 1e9+7;
    int valueAfterKSeconds(int n, int k) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,1));

        for(int i = 1;i<=k;i++){
            for(int j = 1;j<n;j++){
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
        return dp[k][n-1];
        // you are given two integers n and k 
        /*
            Initially you start with an array a of n where a[i] = 1 for all 0<=i<=n-1.
            After each second simultaneously update each element to be the sum of all its preceding
            elements plus the element itself. For example after one second a[0] remains the same, a[1] becomes a[0]+a[1] and so on.
            return a[n-1] after l seconds
        */
        
    }
};