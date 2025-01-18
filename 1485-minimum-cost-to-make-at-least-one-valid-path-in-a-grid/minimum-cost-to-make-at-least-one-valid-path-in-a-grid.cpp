class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    const int INF = 1e9;

    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int dijkstra(vector<long long>& dist, vector<vector<pair<int, int>>>& graph) {
        int n = graph.size();
        using T = pair<long long, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        int start = 0;
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            const auto [cdist, node] = pq.top();
            pq.pop();
            if (cdist != dist[node]) {
                continue;
            }
            for (const pair<int, int>& i : graph[node]) {
                if (cdist + i.second < dist[i.first]) {
                    pq.push({dist[i.first] = cdist + i.second, i.first});
                }
            }
        }
        return dist[n - 1] == LLONG_MAX ? -1 : dist[n - 1];
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<int, int>>> graph(n * m);
        vector<long long> dist(n * m, LLONG_MAX);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int value = grid[i][j];
                int curNode = i * m + j; 

                for (int dir = 0; dir < directions.size(); dir++) {
                    int curX = i + directions[dir][0];
                    int curY = j + directions[dir][1];
                    if (isValid(curX, curY, n, m)) {
                        int fourNode = curX * m + curY;  
                        if (dir == value - 1) {  
                            graph[curNode].emplace_back(fourNode, 0);
                        } else {  
                            graph[curNode].emplace_back(fourNode, 1);
                        }
                    }
                }
            }
        }

        int answer = dijkstra(dist, graph);
        return answer;
    }
};
