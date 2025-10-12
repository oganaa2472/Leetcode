class Solution {
public:
    int strip(int v){
        int ans = 1;
        for(int i = 2;i<=sqrt(v);i++){
            int cnt = 0;
            while(v%i==0){
                v=v/i;
                cnt++;
            }
            if(cnt%2==1) ans*=i;
        }
        if(v>1) ans *=v;
        return ans; 
    }   
    void dfs(int u,int p, vector<vector<int>>&adj,
    map<int,int> &cnt,vector<int>&nums,long long &ans){
        int s = strip(nums[u]);
        ans+=cnt[s];
        cnt[s]++;
        for(auto v:adj[u]){
            if(v==p) continue;
            dfs(v,u,adj,cnt,nums,ans);
        }
        cnt[s]--;
    }
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        
        
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
             adj[e[1]].push_back(e[0]);
        }
        map<int,int> cnt;
        long long ans = 0;
        dfs(0,-1,adj,cnt,nums,ans);
        return ans;
    }
};