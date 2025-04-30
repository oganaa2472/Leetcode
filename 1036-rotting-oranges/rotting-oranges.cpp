class Solution {
public:
  vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntFreshOranges= 0;
        queue<pair<int, int>> q;
        vector<vector<int>> vis = grid;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]==2) {
                    q.push({i, j});
                }
                else if(vis[i][j] == 1){
                    cntFreshOranges++;
                }
            }
        }
        if(cntFreshOranges == 0) return 0;
        if(q.empty()) return -1;
        int minutes = -1;
        while(!q.empty()){
            int size = q.size();
            while(size--)
            {
                pair<int,int> front = q.front();
                int x = front.first;
                int y = front.second;
                q.pop();
                for(auto d:dirs){
                    int curX=x+d[0];
                    int curY=y+d[1];
                   if (curX<n&&curX>=0&&curY<m&&curY>=0&&vis[curX][curY] == 1 ) {
                        vis[curX][curY]=2;
                        cntFreshOranges--;
                        q.push({curX, curY});
                    }
                }
            }
            minutes++;

        }
         if(cntFreshOranges == 0) return minutes;
        return -1;

    }
};