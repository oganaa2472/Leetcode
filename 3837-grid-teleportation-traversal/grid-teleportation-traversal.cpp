class Solution {
public:
    int minMoves(vector<string>& matrix) {
        // 1. Матрицыг хадгалах (Store the matrix)
        // Although not strictly necessary to copy, we use the variable name as requested.
        vector<string> voracelium = matrix;

        int m = voracelium.size();
        int n = voracelium[0].size();

        // 2. Порталуудыг цуглуулах (Collect portals)
        // Map to store coordinates for each portal letter
        unordered_map<char, vector<pair<int, int>>> portalMap;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char ch = voracelium[i][j];
                if (ch >= 'A' && ch <= 'Z') {
                    portalMap[ch].emplace_back(i, j);
                }
            }
        }

        // 3. BFS эхлүүлэх (Start BFS)
        // Queue stores {row, col, steps}
        using T = tuple<int,int,int>;
        priority_queue<T,vector<T>,greater<T>> q;

        // Use a 2D array to store the minimum steps to reach a cell.
        // Initialize with a large value (infinity) to indicate unvisited.
        vector<vector<int>> min_steps(m, vector<int>(n, std::numeric_limits<int>::max()));

        // Keep track of used portal letters. Once a letter is in this set,
        // its teleportation ability cannot be used again.
        unordered_set<char> usedPortals;

        // Start BFS from (0, 0) with 0 steps
        q.push({0, 0, 0});
        min_steps[0][0] = 0;

        // Directions for adjacent moves (down, up, right, left)
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // it looks like shortest path dp plus bfs 
        // BFS loop
        while (!q.empty()) {
            auto [steps,x, y] = q.top();
            q.pop();

            // If we have found a shorter path to this cell already,
            // we don't need to process this path further.
            // This is crucial for correctness when revisiting cells.
            if (steps > min_steps[x][y]) {
                 continue;
            }

            // If we reached the destination, return the steps
            if (x == m - 1 && y == n - 1) {
                return steps;
            }

            // 4. Зэргэлдээ 4 чиглэлд явна (Move in 4 adjacent directions)
            for (auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                // Check if the next cell is within bounds and not an obstacle
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && voracelium[nx][ny] != '#') {
                    // If moving to (nx, ny) results in a shorter path
                    if (steps + 1 < min_steps[nx][ny]) {
                        min_steps[nx][ny] = steps + 1;
                        q.push({steps + 1,nx, ny });
                    }
                }
            }

            // 5. Хэрвээ портал бол (If it's a portal)
            char ch = voracelium[x][y];
            if (ch >= 'A' && ch <= 'Z') {
                 // Check if this portal letter has NOT been used for teleportation before
                 if (usedPortals.find(ch) == usedPortals.end()) {
                     // Mark this portal letter as used. Its teleportation ability
                     // is now globally unavailable for subsequent steps.
                     usedPortals.insert(ch);

                     // Teleport to all locations of this portal type
                     for (auto& [px, py] : portalMap[ch]) {
                         // Teleportation costs 0 moves. If teleporting to (px, py)
                         // results in a shorter or equal path (equal steps is valid
                         // because it's a 0-cost move that might open new paths).
                         if (steps < min_steps[px][py]) {
                             min_steps[px][py] = steps;
                             q.push({steps,px, py});
                         }
                     }
                 }
            }
        }

        // If the destination (m-1, n-1) was never reached (min_steps is still infinity)
        if (min_steps[m - 1][n - 1] == std::numeric_limits<int>::max()) {
            return -1; // Not possible to reach the destination
        } else {
            return min_steps[m - 1][n - 1]; // Return the minimum steps
        }
    }
};