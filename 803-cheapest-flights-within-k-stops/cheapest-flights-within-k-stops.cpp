
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }

        queue<tuple<int,int,int>> q;

        q.push({0,src,0});
        vector<int> dist(n,1e9);
     
        while(!q.empty()){
            auto [stop,node,cost] = q.front();
            q.pop();
            if(stop>k) continue;
            for(auto it:adj[node]){
                int v = it.first;
                int w = it.second;
                if(cost+w<dist[v]&&stop<=k){
                    dist[v] = cost+w;
                    q.push({stop+1,v,cost+w});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};