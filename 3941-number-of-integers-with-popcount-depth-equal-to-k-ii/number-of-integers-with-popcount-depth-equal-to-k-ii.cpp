struct SegmentTree {
    int n;
    vector<long long> tree;

    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0LL);
    }

    void update(int idx, long long val, int node, int start, int end) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(idx, val, 2 * node, start, mid);
        else
            update(idx, val, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int idx, long long val) { update(idx, val, 1, 0, n - 1); }

    long long query(int l, int r, int node, int start, int end) {
        if (r < start || l > end)
            return 0LL;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query(l, r, 2 * node, start, mid) +
               query(l, r, 2 * node + 1, mid + 1, end);
    }

    long long query(int l, int r) { return query(l, r, 1, 0, n - 1); }
};
class Solution {
public:
    unordered_map<long long, int> dp;

    int popCount(long long x) {
        if (x == 1)
            return 0;
        if (dp.count(x))
            return dp[x];
        int cnt = __builtin_popcountll(x);
        return dp[x] = 1 + popCount(cnt);
    }

    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        int n = (int)nums.size();
        vector<SegmentTree> segs;

        for (int i = 0; i < 7; i++) {
            segs.push_back(SegmentTree(n));
        }
        vector<int> dep(n);
        for (int i = 0; i < n; i++) {
            dep[i] = popCount(nums[i]);
            segs[dep[i]].update(i, 1LL);
        }
        vector<int> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int l = (int)q[1], r = (int)q[2], k = (int)q[3];
                if (k >= 7) {
                    ans.push_back(0);
                } else {
                    ans.push_back((int)segs[k].query(l, r));
                }
            } else {
                int idx = (int)q[1];
                long long val = q[2];
                int old = dep[idx];
                segs[old].update(idx, 0LL);
                dep[idx] = popCount(val);
                segs[dep[idx]].update(idx, 1LL);
            }
        }
        return ans;
    }
};
