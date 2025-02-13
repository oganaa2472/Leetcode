class Solution {
public:
    int numDistinct(string s, string t) {
        int n = (int)s.size(), m = (int)t.size();
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(m+1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = 1; // Хоосон "t" нэг л янзаар орно

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) { // `j` нь `i`-ээс их болох ёсгүй
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};