class Solution {
public:
    vector<int> dp;
    int solve(int n){
        if(dp[n]!=-1) return dp[n];
        if(n==1) return 1;
        else if(n==2) return 2;    
        dp[n] = solve(n-1)+solve(n-2);
        return dp[n];
    }
    int climbStairs(int n) {
        dp.resize(n+1,-1);
       
        return solve(n);
    }
};