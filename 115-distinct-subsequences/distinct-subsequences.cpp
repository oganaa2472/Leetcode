class Solution {
public:
    int n,m;
    vector<vector<int>> dp;

    int solve(int i,int j, string& s,string& t){
        if (j == m) return 1; 
        if (i == n) return 0;  
        if (dp[i][j] != -1) return dp[i][j]; 

        int ans = solve(i + 1, j, s, t); 

        if (s[i] == t[j]) 
            ans += solve(i + 1, j + 1, s, t);

        return dp[i][j] = ans; 
    }
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(0,0,s,t);
    }
};