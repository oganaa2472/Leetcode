class Solution {
public:
    void dfs(int u,vector<vector<int>>& isConnected,vector<bool>& vis){
        vis[u] = true;
        for(int i = 0;i<isConnected.size();i++){
            if(!vis[i]&&isConnected[u][i]){
                dfs(i,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       
        int n = isConnected.size();
        int numberOfComponents = 0;
        vector<bool> visit(n);

        for(int i = 0;i<n;i++){
            if(!visit[i]){
                numberOfComponents++;
                dfs(i,isConnected,visit);
            }
        }
        return numberOfComponents;
    }
};