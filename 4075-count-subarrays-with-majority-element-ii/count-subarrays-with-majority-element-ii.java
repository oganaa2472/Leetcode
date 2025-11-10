
class SegmentTree {
    int n;
    int[] seg;
    SegmentTree(int n){
        this.n = n;
        seg = new int[4 * n];
    }

    void update(int node, int start, int end, int idx) {
        if(start == end) {
            seg[node]++;
            return;
        }
        int mid = (start + end) / 2;
        if(idx <= mid) update(2*node+1, start, mid, idx);
        else update(2*node+2, mid+1, end, idx);
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }

    int query(int node, int start, int end, int l, int r) {
        if(start > end || start > r || end < l) return 0;
        if(start >= l && end <= r) return seg[node];
        int mid = (start + end) / 2;
        int left = query(2*node+1, start, mid, l, r);
        int right = query(2*node+2, mid+1, end, l, r);
        return left + right;
    }
}
class Solution {
    public long countMajoritySubarrays(int[] nums, int target) {
          int n = nums.length;
        SegmentTree st = new SegmentTree(2*n + 2);
        int pre = n + 1;

        long ans = 0;
        st.update(0, 0, 2*n+1, pre);

        for(int i = 0; i < n; i++) {
            pre += (nums[i] == target ? 1 : -1);
            long val = st.query(0, 0, 2*n+1, 0, pre - 1);
            ans += val;
            st.update(0, 0, 2*n+1, pre);
        }

        return ans;
    }
}