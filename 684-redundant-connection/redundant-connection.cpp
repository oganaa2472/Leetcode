struct DSU{
    vector<int> parent, size;
    int num_sets;
    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1,-1);
        for(int i = 0;i<=n;i++){
            parent[i] = i;
        }
        num_sets=n;
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a,int b){
        a = find(a);
        b = find(b);
        if(a==b) return false;
        if(size[a]<size[b]) swap(a,b);
        parent[b] = a;
        size[a]+=size[b];
        num_sets--;
        return true;
    }
    int count() const {
        return num_sets;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int a = dsu.find(u);
            int b = dsu.find(v);
            if(a==b){
                return {u,v};
            }
            dsu.unite(u,v);
        }
        return {-1,-1};
    }
};