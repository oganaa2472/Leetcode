
class Solution {
public:
    vector<int> tree;
    int n;

    void update(int node, int start, int end, int idx) {
        if (start == end) {
            tree[node]++;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid) {
            update(node * 2, start, mid, idx);
        } else {
            update(node * 2 + 1, mid + 1, end, idx);
        }

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int query(int node, int start, int end,
              int left, int right) {

        // No overlap
        if (right < start || end < left)
            return 0;

        // Complete overlap
        if (left <= start && end <= right)
            return tree[node];

        int mid = (start + end) / 2;

        return query(node * 2, start, mid, left, right)
             + query(node * 2 + 1, mid + 1, end, left, right);
    }

    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();

        vector<int> sorted = nums;

        // Coordinate Compression
        sort(sorted.begin(), sorted.end());

        sorted.erase(
            unique(sorted.begin(), sorted.end()),
            sorted.end()
        );

        tree.assign(4 * n + 4, 0);

        vector<int> ans(n);

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            int rank = lower_bound(
                sorted.begin(),
                sorted.end(),
                nums[i]
            ) - sorted.begin() + 1;

            // Count elements smaller than nums[i]
            ans[i] = query(
                1, 1, n,
                1, rank - 1
            );

            // Insert current element
            update(1, 1, n, rank);
        }

        return ans;
    }
};
