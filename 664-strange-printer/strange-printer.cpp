class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp, string& s){
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int min_ans=INT_MAX;
        if(s[i]==s[j]) return solve(i+1,j,dp,s);
        for(int k = i;k<j;k++){
            int p = solve(i,k,dp,s)+solve(k+1,j,dp,s);
            min_ans = min(min_ans,p);
        }
        return dp[i][j] = min_ans;
    }
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,dp,s);
    }
};