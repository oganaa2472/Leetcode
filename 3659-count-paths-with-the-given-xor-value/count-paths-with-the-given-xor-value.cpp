int dp[300][300][32];
class Solution {
public:
int m , n ;
    int MOD = 1e9 + 7;
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        n = grid[0].size();
        m= grid.size();
        memset(dp,-1,sizeof(dp));
        return paths(grid,0,0,0,k)%MOD;
    }
    int paths(vector<vector<int>>& grid,int i, int j,int curr, int k){
        if(i >= m or j >= n) return 0;
        if(i == m-1 and j == n-1){
            return (grid[i][j] xor curr) == k;
        }
        if(dp[i][j][curr] != -1) return dp[i][j][curr];
        return dp[i][j][curr] = (paths(grid,i+1,j,curr xor grid[i][j], k)%MOD +  paths(grid,i,j+1,curr xor grid[i][j], k)%MOD)%MOD; 

    }
};