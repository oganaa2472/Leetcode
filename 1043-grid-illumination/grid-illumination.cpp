class Solution {
public:
    vector<vector<int>> direction = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0},
        {1, 1}, {-1, -1}, {-1, 1}, {1, -1}
    };

    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> row, col, diag1, diag2;
        map<pair<int, int>, int> mp;

       
        for (auto& lamp : lamps) {
            int x = lamp[0], y = lamp[1];
            if (mp[{x, y}] > 0) continue; 
            mp[{x, y}]++;
            row[x]++;
            col[y]++;
            diag1[x + y]++;
            diag2[x - y]++;
        }

        vector<int> answer(queries.size(), 0);

       
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0], y = queries[i][1];
            if (row[x] > 0 || col[y] > 0 || diag1[x + y] > 0 || diag2[x - y] > 0) {
                answer[i] = 1;
            }
            for (auto& d : direction) {
                int newX = x + d[0], newY = y + d[1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < n) {
                    if (mp[{newX, newY}] > 0) {
                    
                        mp[{newX, newY}]--;
                        if (mp[{newX, newY}] == 0) {
                            row[newX]--;
                            col[newY]--;
                            diag1[newX + newY]--;
                            diag2[newX - newY]--;
                            mp.erase({newX, newY});
                        }
                    }
                }
            }

            
            if (mp[{x, y}] > 0) {
                mp[{x, y}]--;
                if (mp[{x, y}] == 0) {
                    row[x]--;
                    col[y]--;
                    diag1[x + y]--;
                    diag2[x - y]--;
                    mp.erase({x, y});
                }
            }
        }

        return answer;
    }
};
