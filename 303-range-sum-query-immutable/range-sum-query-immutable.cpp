class NumArray {
    vector<int>arr;
    vector<int>Tree;

    void build(int node, int start, int end) {
        if(start == end) {
            Tree[node] = arr[start];
            return; 
        }

        int mid = (start + end) / 2;

        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);

        Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
    }

    int query(int node, int start, int end, int L, int R) {
        if(end < L || R < start) return 0;

        if(end <= R && start >= L) return Tree[node];

        int mid = (start + end) / 2;

        int left = query(node * 2, start, mid, L, R);

        int right = query(node * 2 + 1, mid + 1, end, L, R);

        return left + right;
    }

public:

    NumArray(vector<int>& nums) {
        arr = nums;
        Tree.resize(4 * nums.size());
        build(1, 0, arr.size() - 1);
    }
    
    int sumRange(int L, int R) {
        return query(1, 0, arr.size() - 1, L, R);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */