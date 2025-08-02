class Solution {
public:
    vector<vector<int>> grid,dp;
    int solve(int j,int digit){
        int n = grid.size();
        int m = grid[0].size();
        if(j>=m) return 0;
        if(dp[j][digit]!=-1) return dp[j][digit];
        int cost = 0;
        for(int i = 0;i<n;i++){
            if(grid[i][j]!=digit) cost++;
        }
        int minAns = INT_MAX;

        for(int d = 0;d<=9;d++){
            if(d!=digit){
                minAns =min(minAns,cost+solve(j+1,d));
            }
        }
        return dp[j][digit] = minAns;

    }
    int minimumOperations(vector<vector<int>>& grid) {
        this->grid = grid;
        int m = grid[0].size();
        dp.resize(m,vector<int>(10,-1));
        int ans = INT_MAX;
        for(int digit = 0;digit<10;digit++){
            ans = min(ans,solve(0,digit));
        }
        return ans;
    }
};