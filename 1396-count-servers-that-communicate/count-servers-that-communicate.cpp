class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int> col;
        unordered_map<int,int> row;

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    col[j]++;
                    row[i]++;
                }
            }
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if (row[i] > 1 || col[j] > 1) {
                        answer++;
                    }
                }
            }
        }
        return answer;
    }
};