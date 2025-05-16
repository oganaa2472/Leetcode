class Solution {
public:
     int bfs(int i, vector<int>&vis, vector<int>adj[]){
        vis[i] = 1;
        queue<int>q;
        q.push(i);
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto val : adj[node]){
                if(!vis[val]){
                    vis[val] = 1;
                    q.push(val);
                    count++;
                }
            }
        }
        return count;
    }
    vector<int>topoSort(vector<int>&inDegree, vector<int>adj[]){
        queue<int>q;
        for(int i = 0;i<inDegree.size(); i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto val : adj[node]){
                inDegree[val]--;
                if(inDegree[val] == 0) q.push(val);
            }
        }
        return topo;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>adj[n];
        for(int i = 0;i <n; i++){
            if(edges[i] != -1){
                adj[i].push_back(edges[i]);
            }
        }
        vector<int>inDegree(n, 0);
        for(auto val : edges){
            if(val != -1) {
                inDegree[val]++;
            }
        }
        vector<int>topo = topoSort(inDegree, adj);
        vector<int>vis(n, 0);
        for(auto val : topo){
            vis[val] = 1;
        }
        int maxi = INT_MIN;
         for(int i = 0; i<n; i++){
            if(!vis[i]){
                maxi = max(bfs(i, vis, adj), maxi);
            }
        }
        if(maxi < 0) return -1;
        return maxi+1;
    }
};