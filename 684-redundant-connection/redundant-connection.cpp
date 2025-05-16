class Solution {
public:
    vector<int> height;
    vector<int> parent;
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void unionFind(int a,int b){
        
        if (height[a] < height[b])
            swap(a, b);
        parent[b] = a;
        if (height[a] == height[b])
        height[a]++;
        
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1,0);
        height.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
        for(int i = 0;i<edges.size();i++){
             int a = find_set(edges[i][0]);
             int b = find_set(edges[i][1]);
             if(a==b){
                return {edges[i][0],edges[i][1]};
             }
             unionFind(a,b);
        }
        return {};

    }
 

};