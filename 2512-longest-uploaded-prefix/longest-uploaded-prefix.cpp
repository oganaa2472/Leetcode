class SegmentTree {
public:
    vector<int> tree;
    int size;
    
    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n, 0);
    }
    
    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            update(i, v, 2 * x + 1, lx, mid);
        } else {
            update(i, v, 2 * x + 2, mid, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }

    int longestPrefix(int x, int lx, int rx) {
        if (tree[x] == 0) return lx;
        if (rx - lx == 1) return rx;

        int mid = (lx + rx) / 2;
        if (tree[2 * x + 1] < mid - lx) {
            return longestPrefix(2 * x + 1, lx, mid);
        } else {
            return longestPrefix(2 * x + 2, mid, rx);
        }
    }

    int longestPrefix() {
        return longestPrefix(0, 0, size);
    }
};

class LUPrefix {
public:
    SegmentTree st;

    LUPrefix(int n) : st(n) {}

    void upload(int video) {
        st.update(video - 1, 1);
    }

    int longest() {
        return st.longestPrefix();
    }
};
