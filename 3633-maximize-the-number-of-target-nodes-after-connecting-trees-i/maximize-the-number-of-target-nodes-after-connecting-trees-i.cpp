class Solution {
public:
    void dfs(int parent,int cur,int k,int curIndex,int height,vector<int>& count, vector<vector<int>>& adj){
        if(k<=height) return;
        count[curIndex]++;
        for (auto node : adj[cur]) { 
            if(parent!=node){
                dfs(cur,node,k,curIndex,height+1,count,adj);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        vector<vector<int>> adj(n+1);
        vector<int> check(n+1,0);
        for(auto ed:edges1){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        } 
        for(int i = 0;i<n;i++){
            dfs(-1,i,k+1,i,0,check,adj);
        }


        int m = edges2.size()+1;
        vector<vector<int>> adj1(m+1);
        vector<int> check1(m+1,0);
        for(auto ed:edges2){
            adj1[ed[0]].push_back(ed[1]);
            adj1[ed[1]].push_back(ed[0]);
        } 
        for(int i = 0;i<m;i++){
            dfs(-1,i,k,i,0,check1,adj1);
        }
        for(int i = 0;i<m;i++){
           cout<<check1[i]<<" ";
        }
        cout<<endl;
        int mx = *max_element(check1.begin(),check1.end());

        vector<int> ans(n,0);
        for(int i = 0;i<n;i++){
            ans[i] = check[i]+mx;
        }
        return ans;

    }
};