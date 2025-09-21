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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for(int i = 0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    dsu.unite(i,j);
                }
            }
        }
        return dsu.count();
    }
};