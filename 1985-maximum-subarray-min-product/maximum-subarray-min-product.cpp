class SegmentTree {
    int n;
    vector<pair<int, long long>> tree;

public:
    SegmentTree(int n, vector<int>& nums) : n(n) {
        while ((this->n & (this->n - 1)) != 0) this->n++;
        build(n, nums);
    }

    void build(int n, vector<int>& nums) {
        tree.resize(2 * this->n, {-1, LLONG_MAX});
        for (int i = 0; i < n; i++) {
            tree[this->n + i] = {i, nums[i]};
        }
        for (int i = this->n - 1; i > 0; i--) {
            tree[i] = min(tree[i << 1], tree[i << 1 | 1], [](auto& a, auto& b) { return a.second < b.second; });
        }
    }

    int query(int l, int r) {
        pair<int, long long> res = {-1, LLONG_MAX};
        l += this->n;
        r += this->n + 1;
        while (l < r) {
            if (l & 1) res = min(res, tree[l++], [](auto& a, auto& b) { return a.second < b.second; });
            if (r & 1) res = min(res, tree[--r], [](auto& a, auto& b) { return a.second < b.second; });
            l >>= 1;
            r >>= 1;
        }
        return res.first;
    }
};

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        SegmentTree segTree(nums.size(), nums);
        vector<long long> prefixSum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        return rec(0, nums.size() - 1, nums, prefixSum, segTree) % MOD;
    }

private:
    long long rec(int l, int r, vector<int>& nums, vector<long long>& prefixSum, SegmentTree& segTree) {
        if (l > r) return 0;
        int minIdx = segTree.query(l, r);
        long long totalSum = prefixSum[r + 1] - prefixSum[l];
        long long cur = totalSum * nums[minIdx];
        long long left = rec(l, minIdx - 1, nums, prefixSum, segTree);
        long long right = rec(minIdx + 1, r, nums, prefixSum, segTree);
        return max(cur, max(left, right));
    }
};