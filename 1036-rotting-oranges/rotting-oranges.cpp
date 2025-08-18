class Solution {
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); // ✅ correct column count
        queue<pair<int,int>> q;
        int unrotten = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) unrotten++;
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }
        if(q.empty()) {
            if(unrotten==0) return 0;
            return -1;
        }
        int time = -1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x, y] = q.front(); q.pop();
                for(auto d : dir){
                    int newX = x + d[0], newY = y + d[1];
                    if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1){
                        unrotten--;
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                    }
                }
            }
            time++; // ✅ Only count minutes when oranges are still rotting
        }

        return (unrotten == 0) ? time : -1;
    }
};
