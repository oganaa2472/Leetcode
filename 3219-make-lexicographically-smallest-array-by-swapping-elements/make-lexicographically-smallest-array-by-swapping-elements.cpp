class UnionFind { // usual UnionFind class
    vector<int> root, rank;

public:
    UnionFind(int n) : root(n), rank(n) {
        rank.assign(n, 1);
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x) { // Path compression
        if (x == root[x])
            return x;
        else
            return root[x] = Find(root[x]);
    }

    bool Union(int x, int y) { // Union by rank
        int rX = Find(x), rY = Find(y);
        if (rX == rY)
            return 0;
        if (rank[rX] > rank[rY])
            swap(rX, rY);
        root[rX] = rY;
        if (rank[rX] == rank[rY])
            rank[rY]++;
        return 1;
    }
    bool connected(int x, int y) { return Find(x) == Find(y); }
};

struct Group {
    int lo, hi;
    vector<int> idx;
    Group() : lo(INT_MAX), hi(0) {}
    void add(int x, int i) {
        lo = min(x, lo);
        hi = max(x, hi);
        idx.push_back(i);
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        const int M = *max_element(nums.begin(), nums.end());
        const int n = nums.size();
        const int L = limit + 1;
        const int N = (M + L) / L;

        if (n == 1) return nums;
        if (N == 1) { // Special case: all numbers in the same group
            sort(nums.begin(), nums.end());
            return nums;
        }
    
        UnionFind G(N);
        vector<Group> seq(N);

        // Create groups and merge based on range
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int idx = x / L;
            seq[idx].add(x, i);

            // Merge with previous group if ranges overlap
            if (idx> 0 && !seq[idx-1].idx.empty() && seq[idx-1].hi + limit >= x) {
                G.Union(idx - 1, idx);
            }

            // Merge with next group if ranges overlap
            if (idx < N-1 && !seq[idx+1].idx.empty() && seq[idx+1].lo - limit <= x) {
                G.Union(idx, idx + 1);
            }
        }

        // Process connected groups
        vector<int> ind;
        for (int i = 0; i < N; i++) {
            if (!seq[i].idx.empty()) {
                ind.insert(ind.end(), seq[i].idx.begin(), seq[i].idx.end());
            }

            // If we've reached the end of a connected component or the last group
            if (i == N - 1 || !G.connected(i, i + 1)) {
                if (!ind.empty()) {
                    vector<int> values;
                    for (int idx : ind) values.push_back(nums[idx]);

                    // Sort indices and values for the current connected component
                    sort(ind.begin(), ind.end());
                    sort(values.begin(), values.end());

                    for (int j = 0; j < ind.size(); j++) nums[ind[j]] = values[j];
                    ind.clear(); // Reset for the next connected component
                }
            }
        }

        return nums;
    }
};