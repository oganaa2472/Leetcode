class Solution {
public:
    int dfs(int i,int k,int n,vector<int>&memo,vector<vector<bool>>&dp){
            if (i >= memo.size()) return 0; 
            if (memo[i] != -1) return memo[i];

            int maxCount = 0;

           
            for (int j = i + k - 1; j < n; j++) {
                if (dp[i][j]) {
                    int currentCount = 1 + dfs(j + 1,k,n,memo,dp);
                    maxCount = max(maxCount, currentCount);
                }
            }

            
            maxCount = max(maxCount, dfs(i + 1,k,n,memo,dp));
            return memo[i] = maxCount;
        }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i = 0;i<n;i++){
            dp[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; 
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }
        vector<int> memo(n, -1);
        return dfs(0,k,n,memo,dp);
    }
};