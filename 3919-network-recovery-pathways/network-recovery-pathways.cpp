#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
const ll mod = 1e9 + 7, MX = 2e5 + 5;
const ll INF = 1e18;
constexpr ll pct(int x) { return __builtin_popcount(x); }
constexpr ll bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

vector<int> topologicalSort(int n , vector<vector<int>>& g) {
   vector<int> indeg(n, 0);
   for (int i = 0; i < n; ++i) {
      for (auto &adj_node : g[i])
         ++indeg[adj_node];
   }
   queue<int> q;
   vector<int> ts;
   for (int i = 0; i < n; ++i)
      if (!indeg[i]) q.push(i);

   while (!q.empty()) {
      int u = q.front(); q.pop();
      ts.pb(u);
      for (int v : g[u])
         if (--indeg[v] == 0) q.push(v);
   }
   return ts;
}

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], c = e[2];
            adj[u].pb({v,c});
            g[u].pb(v);
        }
        vector<int> ts = topologicalSort(n, g);
        auto ok = [&](int x){
            vector<ll> d(n, INF);
            d[0] = 0;
            for (int u : ts) if (d[u] < INF) {
                for (auto &p : adj[u]) {
                    int v = p.ff, c = p.ss;
                    if (c < x || !online[v]) continue;
                    d[v] = min(d[v], d[u] + c);
                }
            }
            return d[n-1] <= k;
        };
        if (!ok(0)) return -1;
        int l = 0, h = 0;
        for (auto &e : edges) h = max(h, e[2]);
        while (l < h) {
            int md = l + (h - l + 1) / 2;
            if (ok(md)) l = md;
            else h = md - 1;
        }
        return l;
    }
};