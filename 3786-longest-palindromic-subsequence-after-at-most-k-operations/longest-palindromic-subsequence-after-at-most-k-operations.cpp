class Solution {
public:
    string s;
    vector<vector<vector<int>>> dp;
    int solve(int i ,int j,int k){
        if(i==j) return 1;
        if(i>j) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];

        int diff = min(abs(s[i]-s[j]),26-abs(s[i]-s[j]));
        if(s[i]==s[j]){
            dp[i][j][k] = 2+ solve(i+1,j-1,k);
        }
        if(diff>k){
            int inc = solve(i+1,j,k);
            int exc = solve(i,j-1,k);
            return dp[i][j][k] = max(inc,exc);
        }
        else{
            int inc =2 + solve(i+1,j-1,k-diff);
            // int exc =1+ solve(i,j-1,k-diff);
            int a = solve(i+1,j,k);
            int b = solve(i,j-1,k);
            return dp[i][j][k] = max({inc,a,b});
        }

    }
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        this->s = s;
        dp.resize(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return solve(0,n-1,k);
    }
};