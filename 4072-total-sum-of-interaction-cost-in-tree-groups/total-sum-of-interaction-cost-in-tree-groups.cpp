#define ll long long
class Solution {
public:
    void f(int i,int par,vector<int> adj[],vector<int>&g,vector<vector<ll>>& ans,vector<vector<int>>&count){
        for(auto&j:adj[i]){
            if(j==par) continue;
            f(j,i,adj,g,ans,count);
            for(int k=0;k<=20;k++){
                count[i][k]+=count[j][k];
                ans[i][k]+=ans[j][k]+count[j][k];
            }
        }

        count[i][g[i]]++;
    }
    void dfs(int i,int par,vector<int> adj[],vector<int>&g,vector<vector<ll>>& ans,vector<vector<int>>&count,vector<ll>&res,vector<ll> part){
        res[i]=ans[i][g[i]]+(count[0][g[i]]-count[i][g[i]])+part[g[i]];
        for(int k=0;k<21;k++){
            part[k]+=count[0][k]-count[i][k]+ans[i][k];
        }

        for(auto&j:adj[i]){
            if(par==j) continue;
            vector<ll> new_part=part;
            for(int k=0;k<21;k++){
                new_part[k]-=(ans[j][k]+count[j][k]);
            }
            dfs(j,i,adj,g,ans,count,res,new_part);
        }
    }
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<int> adj[n+1];
        for(auto&i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<vector<ll>> ans(n,vector<ll>(21,0));
        vector<vector<int>> count(n,vector<int>(21));
        f(0,-1,adj,group,ans,count);
        vector<ll> res(n);
        vector<ll> part(21);
        dfs(0,-1,adj,group,ans,count,res,part);

        ll total=0;

        for(auto&i:res){
            total+=i;
        }
        
        return total/2;
    }
};