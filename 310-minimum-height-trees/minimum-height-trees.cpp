class Solution {
    
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }

    int remaining = n;

    while (remaining > 2) {
        int leafCount = q.size();
        remaining -= leafCount;

        for (int i = 0; i < leafCount; i++) {
            int leaf = q.front(); q.pop();
            for (int nei : adj[leaf]) {
                degree[nei]--;
                if (degree[nei] == 1) q.push(nei);
            }
        }
    }

    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }

    return result;
    }
};