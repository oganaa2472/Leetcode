#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));

        if (grid[0][0] != 0) return -1;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({1, 0, 0});

        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
        };

        while (!pq.empty()) {
            vector<int> d = pq.top();
            int dist = d[0];
            int x = d[1];
            int y = d[2];
            pq.pop();

            if (x == n - 1 && y == n - 1) return dist;

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0 && dist + 1 < dis[nx][ny]) {
                    dis[nx][ny] = dist + 1;
                    pq.push({dist + 1, nx, ny});
                }
            }
        }

        return -1;
    }
};