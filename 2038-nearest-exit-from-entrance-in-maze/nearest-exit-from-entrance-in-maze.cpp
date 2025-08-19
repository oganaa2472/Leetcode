class Solution {
public:
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<tuple<int,int,int>> pq;
        int n = maze.size();
        int m = maze[0].size();
        pq.push({entrance[0],entrance[1],0});
        maze[entrance[0]][entrance[1]] = '+';
        
        while(!pq.empty()){   // ✅ энд зассан
            auto [x,y,dist] = pq.front();
            pq.pop();
            
            if((x==0||y==0||x==n-1||y==m-1) && !(x==entrance[0] && y==entrance[1])){
                return dist;
            }

            for(auto dir:directions){
                int newX = x+dir[0];
                int newY = y+dir[1];
                if(newX>=0&&newY>=0&&newX<n&&newY<m&&maze[newX][newY]=='.'){
                    maze[newX][newY] = '+';
                    pq.push({newX,newY,dist+1});
                }
            }
        }
        return -1;
    }
};
