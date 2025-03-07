class Solution {
public:
    int n,m;
    vector<vector<int>> grid;
    vector<vector<int>> dir={{1,0},{1,-1},{1,1}};
    vector<vector<vector<int>>> dp;
    int solve(int r1 ,int c1, int c2){
        if(c1<0||c1>=m||c2>=m||c2<0){
            return INT_MIN;
        }
        if(r1==n-1){
            if(c1==c2){
                return grid[r1][c1];
            }else{
                return grid[r1][c1]+grid[r1][c2];
            }
        }
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
        int ans =0;
        int maxi=INT_MIN;
        for (int di = -1;di<=1;di++){
            for(int dj = -1;dj<=1;dj++){
                if(c1==c2){
                    ans = grid[r1][c1] + solve(r1+1,c1+di,c2+dj);
                }else{
                    ans = grid[r1][c1] + grid[r1][c2] + solve(r1+1,c1+di,c2+dj);
                }
                maxi=max(ans,maxi);
            }
        }

        return dp[r1][c1][c2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        this->grid=grid;
        n = grid.size();
        m = grid[0].size();
        dp.assign(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1);
    }
};