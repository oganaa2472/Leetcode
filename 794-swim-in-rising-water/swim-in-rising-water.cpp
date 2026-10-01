#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // Min-heap: {time, r, c}
        priority_queue<tuple<int, int, int>, 
                       vector<tuple<int, int, int>>, 
                       greater<tuple<int, int, int>>> pq;

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            auto [currentTime, r, c] = pq.top();
            pq.pop();

            // Баруун доод буланд хүрсэн бол энэ нь шаардагдах хамгийн бага хугацаа
            if (r == n - 1 && c == n - 1) {
                return currentTime;
            }

            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    // Дараагийн нүдэнд очих хугацаа нь өмнөх хугацаа болон шинэ нүдний өндрийн аль их нь байна
                    int nextTime = max(currentTime, grid[nr][nc]);
                    pq.push({nextTime, nr, nc});
                }
            }
        }

        return 0;
    }
};