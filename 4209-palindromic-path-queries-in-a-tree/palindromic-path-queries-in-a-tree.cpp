#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> in, out, dep, pm, bl, ch;
    vector<vector<int>> up, adj;
    int t, bs, LOG;

    void dfs(int u, int p, int d, int m) {
        in[u] = ++t;
        dep[u] = d;
        up[u][0] = p;
        for (int i = 1; i < LOG; i++)
            up[u][i] = up[up[u][i - 1]][i - 1];
        int nm = m ^ (1 << ch[u]);
        pm[in[u]] = nm;
        for (int v : adj[u])
            if (v != p) dfs(v, u, d + 1, nm);
        out[u] = t;
    }

    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = LOG - 1; i >= 0; i--)
            if (dep[u] - (1 << i) >= dep[v])
                u = up[u][i];
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        in.resize(n);
        out.resize(n);
        dep.resize(n);
        up.assign(n, vector<int>(LOG));
        ch.resize(n);
        for (int i = 0; i < n; i++) ch[i] = s[i] - 'a';
        pm.assign(n + 1, 0);
        t = 0;
        dfs(0, 0, 0, 0);

        bs = sqrt(n) + 1;
        bl.assign(n / bs + 2, 0);
        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string op, c;
            int u, v;
            ss >> op >> u;
            if (op == "update") {
                ss >> c;
                int nc = c[0] - 'a';
                int diff = (1 << ch[u]) ^ (1 << nc);
                int L = in[u], R = out[u];
                int sb = L / bs, eb = R / bs;
                if (sb == eb) {
                    for (int i = L; i <= R; i++) pm[i] ^= diff;
                } else {
                    for (int i = L; i < (sb + 1) * bs; i++) pm[i] ^= diff;
                    for (int b = sb + 1; b < eb; b++) bl[b] ^= diff;
                    for (int i = eb * bs; i <= R; i++) pm[i] ^= diff;
                }
                ch[u] = nc;
            } else {
                ss >> v;
                int l = lca(u, v);
                int mu = pm[in[u]] ^ bl[in[u] / bs];
                int mv = pm[in[v]] ^ bl[in[v] / bs];
                int mask = mu ^ mv ^ (1 << ch[l]);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};