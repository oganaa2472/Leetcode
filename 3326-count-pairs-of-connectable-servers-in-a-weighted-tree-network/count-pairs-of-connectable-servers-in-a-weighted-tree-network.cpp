class Solution {
public:

    vector<int> count;                   // result array
    int signalSpeed;
    vector<vector<pair<int,int>>> adj;   // adjacency list

    int cnt,ss,n;
    void dfs(int u, int parent,int d) {
        if(d%ss==0) cnt++;
       
        for (auto &[v,w] : adj[u]) {
            if (v == parent) continue;
            dfs(v,u,d+w);   
        }
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
       
        ss = signalSpeed;
        int n = edges.size() + 1;
        adj.assign(n, vector<pair<int,int>>());
        vector<int> res(n);
        for (const auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        for (int i = 0; i < n; ++i){
            int ans=0,sum = 0;
            vector<int> temp;
            for(auto [node,distance]:adj[i]){
                cnt = 0;
                dfs(node,i,distance);
                temp.push_back(cnt);
                sum = sum + cnt;
            }
            for(auto el:temp){
                ans+=(sum-el)*el;
            }
        
    
            res[i] = ans/2;
        }
           
        return res;
    }
};