class Solution {
public:
    void dfs(int child,vector<bool>&visited,vector<vector<int>>& adj){
        visited[child] = true;
        for(auto u:adj[child]){
            if(visited[u]==false){
                    dfs(u,visited,adj);
                
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { // Skip i==j and only check upper triangle
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i); // since it's undirected
                }
            }
        }
        vector<bool> visited(n,false);
        int components = 0;
        for(int i = 0;i<n;i++){
            if(visited[i]==false){
                dfs(i,visited,adj);
                components++;
            }
        }
        return components;
    }
};