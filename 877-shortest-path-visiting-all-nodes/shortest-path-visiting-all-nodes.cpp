class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> dist;
    int INF = 1e9;
    int n;

    int tsp(int pos, int mask) {
        if (mask == (1 << n) - 1) return 0; // Бүх хотод очсон тул дуусгавар нөхцөл

        if (dp[pos][mask] != -1) return dp[pos][mask];

        int ans = INF;
        for (int nxt = 0; nxt < n; nxt++) {
            if ((mask & (1 << nxt)) == 0) { // Хэрэв nxt хотод очоогүй бол
                ans = min(ans, dist[pos][nxt] + tsp(nxt, mask | (1 << nxt)));
            }
        }
        return dp[pos][mask] = ans;
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        n = graph.size();
        if (n == 1) return 0; // Зөвхөн 1 хоттой бол 0 байна

        // BFS ашиглаж dist[i][j] буюу хамгийн богино замуудыг тодорхойлно
        dist.assign(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            queue<pair<int, int>> q;
            q.push({i, 0});
            dist[i][i] = 0;
            while (!q.empty()) {
                auto [node, d] = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (dist[i][neighbor] == INF) { // Анх удаа хүрч байгаа бол
                        dist[i][neighbor] = d + 1;
                        q.push({neighbor, d + 1});
                    }
                }
            }
        }

        // DP хүснэгтийг -1-р дүүргэж анхны төлөв үүсгэнэ
        dp.assign(n, vector<int>(1 << n, -1));

        // Бүх хотуудаас эхлэн TSP гүйцэтгэж хамгийн бага замыг олно
        int ans = INF;
        for (int start = 0; start < n; start++) {
            ans = min(ans, tsp(start, 1 << start));
        }
        return ans;
    }
};
