class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>> diagonals;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diagonals[i - j].push_back(grid[i][j]);
            }
        }
        for (auto &p : diagonals) {
            int key = p.first;
            if (key >= 0) {
                // bottom-left triangle (descending)
                sort(p.second.begin(), p.second.end(), greater<int>());
            } else {
                // top-right triangle (ascending)
                sort(p.second.begin(), p.second.end());
            }
        }
        unordered_map<int, int> index; // track pop index
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                grid[i][j] = diagonals[key][index[key]++];
            }
        }

        return grid;


    }
};