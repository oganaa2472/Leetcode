class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n+1);
        for(auto edge:edges){
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool> visited(n,0);

        queue<int> q;
        visited[source] = 1;
        q.push(source);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(front==destination) return true;
            for(auto it:adj[front]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        return false;
    }
};