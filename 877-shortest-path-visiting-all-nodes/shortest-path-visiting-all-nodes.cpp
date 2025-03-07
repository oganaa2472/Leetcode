class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> dist;
    int INF = INT_MAX;
    int n ;
    int tsp(int pos, int mask) {
        if (mask == (1 << n) - 1) return 0;

        if (dp[pos][mask] != -1) return dp[pos][mask];

        int ans = INF;
        for (int nxt = 0; nxt < n; nxt++) {
            if ((mask & (1 << nxt)) == 0) { 
                ans = min(ans, dist[pos][nxt] + tsp(nxt, mask | (1 << nxt)));
            }
        }
        return dp[pos][mask] = ans;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        n = graph.size(); 
        dp.resize(n,vector<int>(1<<n,-1));
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
        int ans = INF;
        for (int start = 0; start < n; start++) {
            ans = min(ans, tsp(start, 1 << start));
        }
        return ans;
    }
};