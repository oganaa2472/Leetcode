class Solution {
public:
    vector<vector<int>> direction=
    {
        {0,1},{1,0},{0,-1},{-1,0},
        {1,1},{-1,-1},{-1,1},{1,-1},
    };
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
    
        unordered_map<int,int> row;
        unordered_map<int,int>  col;
        unordered_map<int,int> diag1;
        unordered_map<int,int> diag2;
        map<pair<int,int>,int> mp;
        int lampSize = lamps.size();
        for(int i = 0;i<lampSize;i++){
            int x = lamps[i][0];
            int y = lamps[i][1];
           if (mp[{x, y}] > 0) continue;
            mp[{x,y}]++;
            row[x]++;
            col[y]++;
            diag1[x+y]++;
            diag2[x-y+n-1]++;
        }

        vector<int> answer(queries.size(),0);
        int qSize = queries.size();
        for(int i = 0;i<qSize;i++){
            int x = queries[i][0];
            int y = queries[i][1];
            if (row[x] > 0 || col[y] > 0 || diag1[x + y] > 0 || diag2[x-y+n-1] > 0) {
                answer[i] = 1;
            }
            for(auto& d:direction){
                int newX=d[0]+x; 
                int newY=d[1]+y;
                // if(newX>=0&&newY>=0&&newY<n&&newX<n){
                   if(mp.count({newX,newY})>0){
                    // if(mp.count(newX)>0)
                        mp[{newX, newY}]--;
                        if( mp[{newX, newY}]==0){
                            row[newX]--;
                        // if(col.count(newY)>0)
                            col[newY]--;
                        // if(diag1.count(x+y)>0)
                            diag1[newX+newY]--;
                        // if(diag2.count(newX)>0)
                            diag2[newX-newY+n-1]--;
                            mp.erase({newX,newY});
                    //    }
                        }
                       
                }

            }
            if (mp[{x, y}] > 0) {
                mp[{x, y}]--;
                if (mp[{x, y}] == 0) {
                    row[x]--;
                    col[y]--;
                    diag1[x + y]--;
                    diag2[x-y+n-1]--;
                    mp.erase({x, y});
                }
            }
            
        }
        return answer;
    }
};