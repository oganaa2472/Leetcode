class SegmentTree {
public:
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * x + 1, lx, mid);
        else
            set(i, v, 2 * x + 2, mid, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return tree[x];
        int mid = (lx + rx) / 2;
        int s1 = sum(l, r, 2 * x + 1, lx, mid);
        int s2 = sum(l, r, 2 * x + 2, mid, rx);
        return s1 + s2;
    }

    int sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

class Solution {
public:
    bool isPeak(vector<int>& nums, int i) {
        int n = nums.size();
        return i > 0 && i < n - 1 && nums[i - 1] < nums[i] && nums[i] > nums[i + 1];
    }

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree seg;
        seg.init(n);

        // Initialize the segment tree with peak information
        for (int i = 1; i < n - 1; ++i) {
            seg.set(i, isPeak(nums, i) ? 1 : 0);
        }

        vector<int> ans;
        for (auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int l = q[1], r = q[2];
                if (r - l <= 1) {
                    ans.push_back(0);  // no possible peak
                } else {
                    ans.push_back(seg.sum(l + 1, r));
                }
            } else if (type == 2) {
                int idx = q[1], val = q[2];
                nums[idx] = val;
                // Update affected positions: idx-1, idx, idx+1
                for (int i = idx - 1; i <= idx + 1; ++i) {
                    if (i > 0 && i < n - 1) {
                        seg.set(i, isPeak(nums, i) ? 1 : 0);
                    }
                }
            }
        }
        return ans;
    }
};
