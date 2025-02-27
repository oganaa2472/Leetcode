class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int mod=1e9+7;
    int solve(int i,int k,int target){
        if(i==n){
            if(target<0) return 0;
            return target==0?1:0;
        }
        if(dp[i][target]!=-1) return dp[i][target]; 
        int ans=0;
        for(int j=1;j<=k;j++){
            if(target-j>=0){
                ans=(ans+solve(i+1,k,target-j))%mod;
            }
        }
       return dp[i][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1,vector<int>(target+1,-1));
        this->n=n;
        return solve(0,k,target);
    }
};