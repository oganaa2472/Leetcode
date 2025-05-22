class Solution {
public:
    int bfs(int node,vector<vector<int>>& adj){
        vector<int> dist(adj.size(), -1);
        vector<int> parent(adj.size(), -1);
        queue<int> q;
        dist[node] = 0;
        q.push(node);

        int shortest = INT_MAX;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                } else if (parent[u] != v) {
                    // Found a cycle: u -> v (not coming from parent)
                    shortest = min(shortest, dist[u] + dist[v] + 1);
                }
            }
        }

        return shortest;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
       
      
         vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // undirected graph
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int len = bfs(i, adj);
            ans = min(ans, len);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};