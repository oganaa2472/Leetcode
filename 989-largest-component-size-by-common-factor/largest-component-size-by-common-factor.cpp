
struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        // sieve algo
        vector<int> spf(maxVal + 1);
        for (int i = 2; i <= maxVal; i++) {
            if (spf[i] == 0) {
                for (long long j = i; j <= maxVal; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }
        DSU dsu(maxVal + 1);

        for (int x : nums) {
            int val = x;
            while (val > 1) {
                int p = spf[val];
                dsu.unite(x, p);  // connect number with its prime factor
                while (val % p == 0) val /= p;
            }

           
        }
         unordered_map<int, int> compSize;
            int ans = 0;
            for (int x : nums) {
                int root = dsu.find(x);
                compSize[root]++;
                ans = max(ans, compSize[root]);
            }

            return ans;
    }
};