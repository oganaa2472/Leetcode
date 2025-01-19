
class Solution {
public:
    // 4 green, red, blue 
    long long dp[(long long)1e5+4][4][4];
    long long n;
    vector<int> colors{1,2,3};
    long long solve(vector<vector<int>>& cost,int index,int prev1,int prev2){
        if(index>=n/2){
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
                        result,cost[index][colors[i]-1]
                        +
                        cost[n-index-1][colors[k]-1]
                        +
                        solve(cost,index+1,colors[i],colors[k])
                    );
                }
            }
        }
        return dp[index][prev1][prev2] = result;
    }

    long long minCost(int n, vector<vector<int>>& cost) {
    
        this->n = n;
        for(int i = 0;i<=n/2;i++){
            for(int j = 0;j<4;j++){
                for(int k = 0;k<4;k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(cost,0,0,0);
    }
};