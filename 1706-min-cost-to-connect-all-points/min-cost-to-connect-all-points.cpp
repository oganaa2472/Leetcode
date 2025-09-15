
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;
    int components;
    int largest;

    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
        components = n;
        largest = 1;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false; // already in same set

        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
      
        return true;
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 0;

    // Create all possible edges with their costs
        vector<pair<int, pair<int, int>>> edges; // {cost, {point1, point2}}
        for (int u = 0; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                int cost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                edges.push_back({cost, {u, v}});
            }
        }
        DSU dsu(n);
        // Sort edges based on cost
        sort(edges.begin(), edges.end());
        int totalCost = 0;
        int edgesUsed = 0;
        for (const auto& [cost, nodes] : edges) {
            if (edgesUsed == n - 1) break; // If we have used n-1 edges, MST is complete
            int u = nodes.first;
            int v = nodes.second;
            if (dsu.unite(u, v)) {
                totalCost += cost;
                edgesUsed++;
            }
        }

        return totalCost;
    }
};