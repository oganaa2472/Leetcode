#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    bool canReach(const vector<vector<int>>& grid, int n, int maxTime) {
        if (grid[0][0] > maxTime) return false;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = true;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1) return true;

            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && 
                    !visited[nr][nc] && grid[nr][nc] <= maxTime) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = grid[0][0];
        int right = n * n - 1;
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canReach(grid, n, mid)) {
                ans = mid;
                right = mid - 1; // Бага хугацаа байх боломжтой эсэхийг шалгах
            } else {
                left = mid + 1;  // Усны түвшин хүрэхгүй байгаа тул нэмэгдүүлэх
            }
        }

        return ans;
    }
};