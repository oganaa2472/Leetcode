class Solution {
public:
    vector<pair<int, int>> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> answer(n, vector<int>(m, INT_MAX)); 
        queue<pair<int, int>> q;

       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    answer[i][j] = 0;
                }
            }
        }

        
        while (!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for (auto dir : directions) {
                int tx = cx + dir.first;
                int ty = cy + dir.second;

               
                if (tx >= 0 && ty >= 0 && tx < n && ty < m) {
                    if (answer[tx][ty] > answer[cx][cy] + 1) {
                        answer[tx][ty] = answer[cx][cy] + 1;
                        q.push({tx, ty});
                    }
                }
            }
        }

        return answer;
    }
};
