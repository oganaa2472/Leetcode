class Solution {
public:
    vector<int> v, rank;

    int find(int a){
        if(v[a] == a)
            return a;
        else
            return v[a] = find(v[a]);
    }

    bool merge(int a, int b){
        int pa = find(a), pb = find(b);
        if(pa == pb)
            return false;
        if(rank[pa] < rank[pb])
            v[pa] =pb;
        else if(rank[pa] > rank[pb])
            v[pb] = pa;
        else{
            v[pa] = pb;
            rank[pb]++;
        }
        return true;
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b){
            return a[2] > b[2];
        });

        int ct = n;
        if(k > n)
            return -1;
        
        v.assign(n, 0);
        rank.assign(n, 1);
        for(int i = 0; i < n; i++)
            v[i] = i;
        
        int res = 0;
        for(int i = 0; i < edges.size(); i++){
            bool flag = merge(edges[i][0], edges[i][1]);
            if(flag)
                ct--;
            if(ct >= k)
                res = i + 1;
            else
                break;
        }

        return res == edges.size() ? 0 : edges[res][2];
    }
};