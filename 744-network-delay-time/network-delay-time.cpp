class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto time:times){
            int a = time[0];
            int b = time[1];
            int c = time[2];
            adj[a].push_back({b,c});
        }
        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            auto [dis,u] = pq.top();
            pq.pop();
            for(auto it:adj[u]){
                int w = it.second;
                int v = it.first;
                if(dist[v] > dist[u]+w){
                    dist[v] = dist[u]+w;
                    pq.push({dist[u]+w,v});
                }
            }
        }
        int mx = 0;
        for(int i = 1;i<=n;i++){
            cout<<dist[i]<<" ";
            if(dist[i]==INT_MAX){
                return -1;
            }else{
                mx = max(mx,dist[i]);
            }
        }
        return mx;
    }
};