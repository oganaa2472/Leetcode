class Solution {
public:
    void dfs(int node,int parent,vector<vector<int>>& adj,vector<int>&vis,int flag,unordered_map<int,int> &mp){
        
        vis[node] =1;
        mp[node] = flag;
        for(auto it:adj[node]){
            if(it==parent||vis[it]){
                continue;
            }
            dfs(it,node,adj,vis,flag,mp);
        }

    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int z=edges.size();
        vector<vector<int>> adj(n,vector<int>(0));
        
        for(int i = 0;i<z;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_map<int,int> mp;
        int flag = 1;
        vector<int> vis(n,0);

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,adj,vis,flag,mp);
                flag++;
            }
        }
        vector<int> marked(flag+1,pow(2,31)-1);

        for(int i = 0;i<z;i++){
            marked[mp[edges[i][0]]] = marked[mp[edges[i][0]]] & edges[i][2];
        }
        vector<int> ans;
        for(int i = 0;i<query.size();i++){
            if(query[i][0]==query[i][1]){
                ans.push_back(0);
            }else if(mp[query[i][0]]==mp[query[i][1]]){
                ans.push_back(marked[mp[query[i][0]]]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }

};