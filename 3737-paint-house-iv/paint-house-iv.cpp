
class Solution {
public:
    // 4 green, red, blue 
    vector<int> colors{1,2,3};
    long long solve(int index,vector<vector<int>>& cost,int prev1,int prev2,vector<vector<vector<long long>>>&dp){
        int n = cost.size();
        if(cost.size()/2<=index){
            return 0;
        }
        if(dp[index][prev1][prev2]!=-1){
            return dp[index][prev1][prev2];
        }
        long long result = LLONG_MAX;
        for(int i = 0;i<3;i++){
            for(int k = 0;k<3;k++){
                if(colors[i]!=colors[k]&&colors[i]!=prev1&&colors[k]!=prev2){
                    result = min(
                        result,cost[index][colors[i]-1]+ cost[n-index-1][colors[k]-1]
                        +
                        solve(index+1,cost,colors[i],colors[k],dp)
                    );
                }
            }
        }
        return dp[index][prev1][prev2] = result;
    }

    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(4,vector<long long>(4,-1)));
        int prev2 = n-(0+1);
        return solve(0,cost,0,0,dp);
    }
};