class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    bool isValid(int i,int j,vector<vector<int>>& grid){
        return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] > 0;
    }

    int dfs(int i ,int j,vector<vector<int>>& grid){
        if (!isValid(i, j, grid)) {
            return 0;
        }
        int current = grid[i][j];
        grid[i][j] = 0;  
        int total = current;
        for (auto& d : dir) {
            int newX = d[0] + i;
            int newY = d[1] + j;
            total += dfs(newX, newY, grid);
        }
        return total;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int answer = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    answer = max(answer,dfs(i,j,grid));
                }
            }
        }
        return answer;
    }
};