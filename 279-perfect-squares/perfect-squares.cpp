#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

class Solution {
public:
    int numSquares(int n) {
        // Queue for the BFS
        std::queue<std::pair<int, int>> q;
        q.push({n, 0});

        std::vector<bool> visited(n + 1, false);
        visited[n] = true;

        // BFS loop
        while (!q.empty()) {
            auto [current, depth] = q.front();
            q.pop();

            // Try subtracting each perfect square less than current
            for (int i = 1; i * i <= current; ++i) {
                int next = current - i * i;
                if (next == 0) return depth + 1; // Found a solution
                
                // If not visited, add to queue
                if (!visited[next]) {
                    q.push({next, depth + 1});
                    visited[next] = true;
                }
            }
        }
        return -1; // Should never reach here
    }
};