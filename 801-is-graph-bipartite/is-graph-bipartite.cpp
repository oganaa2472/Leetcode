class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>&color,int cur){
        color[node] = cur;
        for(int it:graph[node]){
            if(color[it]==-1){
                if(!dfs(it,graph,color,abs(1-cur))) return false;
            }
            else if(color[it]==cur) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i =0;i<n;i++){
            if(color[i] == -1) { 
                if(!dfs(i, graph,color,0))
                    return false; 
            }
        }
        return true;
    }
};