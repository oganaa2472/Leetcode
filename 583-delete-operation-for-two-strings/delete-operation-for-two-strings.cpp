class Solution {
public:
    
    int minDistance(string s, string t) {

        int n = (int)s.size(), m = (int)t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // for (int i = 0; i <= n; i++) dp[i][0] = 1;
        // // for (int i = 0; i <= m; i++) dp[0][i] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) { 
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int lcs = dp[n][m];
        return (n - lcs) + (m - lcs);
        
     
    }
};