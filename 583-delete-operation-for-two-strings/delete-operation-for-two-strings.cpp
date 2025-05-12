class Solution {
public:
    vector<vector<int>> dp;
    int lcs(string& s, string& t, int i, int j) {
        if (i == 0 || j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i-1] == t[j-1])
            return dp[i][j] = 1 + lcs(s, t, i-1, j-1);
        else
            return dp[i][j] = max({dp[i][j],lcs(s, t, i-1, j), lcs(s, t, i, j-1)});
    }
    int minDistance(string s, string t) {

        int n = (int)s.size(), m = (int)t.size();
        dp.resize(n+1, vector<int>(m+1, -1));
        // // for (int i = 0; i <= n; i++) dp[i][0] = 1;
        // // // for (int i = 0; i <= m; i++) dp[0][i] = 1;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) { 
        //         if (s[i-1] == t[j-1])
        //             dp[i][j] = dp[i-1][j-1]+1;
        //         else
        //             dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        //     }
        // }
        
        int  lcs2 = lcs(s,t,n,m);
        // cout<<lcs2<<endl;
        return (n - lcs2) + (m - lcs2);
        
     
    }
};