class Solution {
public:
    vector<int> dp;
    // int solve(int n){
    //     if(dp[n]!=-1) return dp[n];
    //     if(n==1) return 1;
    //     else if(n==2) return 2;    
    //     dp[n] = solve(n-1)+solve(n-2);
    //     return dp[n];
    // }
    int climbStairs(int n) {
        if(n==1||n==2) return n;
        dp.resize(n+1,0);
        dp[0]=0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
};