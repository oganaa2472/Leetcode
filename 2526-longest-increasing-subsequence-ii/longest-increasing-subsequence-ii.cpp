struct SegmentTree {
    int n;
    vector<int> tree;
    SegmentTree(int size) : n(size), tree(4*size, 0) {}

    void update(int node, int l, int r, int pos, int val) {
        if(l == r) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) update(2*node, l, mid, pos, val);
        else update(2*node+1, mid+1, r, pos, val);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if(r < ql || l > qr) return 0;
        if(ql <= l && r <= qr) return tree[node];
        int mid = (l+r)/2;
        return max(query(2*node, l, mid, ql, qr),
                   query(2*node+1, mid+1, r, ql, qr));
    }

    void update(int pos, int val) { update(1, 1, n, pos, val); }
    int query(int l, int r) { if(l>r) return 0; return query(1, 1, n, l, r); }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
    vector<int> vals = nums;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    // coordinate compression
    unordered_map<int,int> mp;
    for(int i=0;i<vals.size();i++) mp[vals[i]] = i+1;

    SegmentTree seg(vals.size());
    int ans = 0;

    for(int x : nums) {
        int left = lower_bound(vals.begin(), vals.end(), x - k) - vals.begin() + 1;
        int right = mp[x]; // compressed index of x
        int dp = 1 + seg.query(left, right-1);
        seg.update(right, dp);
        ans = max(ans, dp);
    }
    return ans;
    }
};