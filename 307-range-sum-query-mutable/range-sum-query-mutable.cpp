class NumArray {
public:
    struct segtree {
        int size;
        vector<int> sums;

        void init(int n) {
            size = n;
            sums.resize(4 * n);
        }

        long long sum(int l, int r, int x, int lx, int rx) {
            if (l > rx || lx > r) return 0; // No overlap
            if (lx >= l && rx <= r) return sums[x]; // Full overlap
            
            int mid = (lx + rx) / 2;
            long long s1 = sum(l, r, 2 * x + 1, lx, mid);      // Left child
            long long s2 = sum(l, r, 2 * x + 2, mid + 1, rx);  // Right child
            return s1 + s2;
        }

        long long sum(int l, int r) {
            return sum(l, r, 0, 0, size - 1);
        }

        void build(vector<int>& a, int x, int lx, int rx) {
            if (lx == rx) {
                sums[x] = a[lx];
                return;
            }
            int mid = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, mid);       
            build(a, 2 * x + 2, mid + 1, rx);   
            sums[x] = sums[2 * x + 1] + sums[2 * x + 2]; 
        }

        void build(vector<int>& a) {
            build(a, 0, 0, size - 1);
        }

        void set(int i, int v, int x, int lx, int rx) {
            if (lx == rx) {
                sums[x] = v;
                return;
            }
            int mid = (lx + rx) / 2;
            if (i <= mid) {
                set(i, v, 2 * x + 1, lx, mid);
            } else {
                set(i, v, 2 * x + 2, mid + 1, rx);
            }
            sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        }

        void set(int i, int v) {
            set(i, v, 0, 0, size - 1);
        }
    };

    segtree st;

    NumArray(vector<int>& nums) {
        st.init(nums.size());
        st.build(nums);
    }

    void update(int index, int val) {
        st.set(index, val);
    }

    int sumRange(int left, int right) {
        return (int)st.sum(left, right);
    }
};
