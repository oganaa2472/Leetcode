class Solution {
public:
    vector<vector<vector<int>>> dp;
    int mod = 1e9+7;
    int n;
    int solve(int i,int l,int a){
        if(i==n) return 1;
        if(dp[i][l][a]!=-1) return dp[i][l][a];
        int ans = solve(i+1,2,a)%mod;
        if(a>0){
            ans=(ans+solve(i+1,2,a-1))%mod;
        }
        if(l>0){
            ans=(ans+solve(i+1,l-1,a))%mod;
        }
        return  dp[i][l][a] = ans%mod;
    }
    int checkRecord(int n) {
        this->n = n;
        dp = (vector<vector<vector<int>>>(n,vector<vector<int>>(3,vector<int>(2,-1))));
        return solve(0,2,1);
    }
};