class Solution {
public:
    int n;
    int m;
    unordered_map<int,int> area;

    int dfs(int i,int j,vector<vector<int>>&grid,int id){
        if(i<0||j<0||i>=n||j>=m||grid[i][j]!=1) return 0;
        grid[i][j] = id;
        return 1 + dfs(i+1,j,grid,id)+
        dfs(i-1,j,grid,id)+
        dfs(i,j+1,grid,id)+
        dfs(i,j-1,grid,id);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int islandId = 2;
        this->n = grid.size();
        this->m = grid[0].size();
        int myAreaId = 2;
        unordered_map<int,int> areas;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    areas[myAreaId] = dfs(i,j,grid,myAreaId);
                    myAreaId++;
                }
            }
        } 
        if (areas.size()==0) {
            return 1;
        }
        if (areas.size() == 1) {
            myAreaId--;
            return (areas[myAreaId] == n*m)
                       ? areas[myAreaId]
                       : areas[myAreaId] + 1;
        }

        int maxArea= 1;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
               
                if (grid[i][j] == 0) {
                    int current = 1;
                    unordered_set<int> neighbor;
                    if (i + 1 < n &&
                        grid[i + 1][j] > 1) {
                        neighbor.insert(
                            grid[i + 1][j]);
                    }
                    if (i - 1 >= 0 &&
                        grid[i - 1][j] > 1) {
                        neighbor.insert(
                            grid[i - 1][j]);
                    }

                   
                    if (j + 1 < m &&
                        grid[i][j + 1] > 1) {
                        neighbor.insert(
                            grid[i][j + 1]);
                    }


                    if (j - 1 >= 0 &&
                        grid[i][j - 1] > 1) {
                        neighbor.insert(
                            grid[i][j - 1]);
                    }

                    for (int id : neighbor) {
                      
                        current += areas[id];
                    }

                    maxArea = max(maxArea, current);
                }
                
            }
            
        
        } 
        return maxArea;
    }
};