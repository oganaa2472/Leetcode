class Solution {
public:
    vector<int> parent, rank;
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto& edge : edges) {
            unionNodes(edge[0], edge[1]);
        }
        vector<int> compSize(n, 0);
        vector<long long> compEdges(n, 0);
        for (int i = 0; i < n; i++) {
            compSize[find(i)]++;
        }
        for (auto& edge : edges) {
            compEdges[find(edge[0])]++;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) {
                if (compEdges[i] == (long long) compSize[i] * (compSize[i] - 1) / 2) {
                    count++;
                }
            }
        }
        return count;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unionNodes(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else if (rank[rx] > rank[ry]) {
            parent[ry] = rx;
        } else {
            parent[ry] = rx;
            rank[rx]++;
        }
    }
};