

typedef int item;
 
struct segtree {
    int size;
    item NEUTRAL_ELEMENT = 0;
    vector<item> sums;
 
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.resize(2 * size);
    }
 
    item merge(item a, item b) {
        return max(a, b);
    }
 
    item single(item v) {
        return v;
    }
 
    item sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return NEUTRAL_ELEMENT;
        if (lx >= l && rx <= r) return sums[x];
 
        int mid = (lx + rx) / 2;
        item s1 = sum(l, r, 2 * x + 1, lx, mid);
        item s2 = sum(l, r, 2 * x + 2, mid, rx);
        return merge(s1, s2);
    }
 
    item sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
 
    void build(vector<item>& a) {
        build(a, 0, 0, size);
    }
 
    void build(vector<item>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                sums[x] = single(a[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        sums[x] = merge(sums[2 * x + 1], sums[2 * x + 2]);
    }
 
    void set(int i, item v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = single(v);
            return;
        }
 
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        sums[x] = merge(sums[2 * x + 1], sums[2 * x + 2]);
    }
 
    void set(int i, item v) {
        set(i, v, 0, 0, size);
    }
 
    int find(item u, int x, int lx, int rx) {
        if (sums[x] < u) return -1;
        if (rx - lx == 1) return lx;
 
        int m = (lx + rx) / 2;
        int res = find(u, 2 * x + 1, lx, m);
        if (res == -1) {
            return find(u, 2 * x + 2, m, rx);
        }
        return res;
    }
 
    int find(item u) {
        return find(u, 0, 0, size);
    }
};

class Solution {
    
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        segtree st;
        int n = fruits.size();
        st.init(n);
        int answer = 0;
        st.build(baskets);
        for(auto f:fruits){
            int t = st.find(f);
            if(t==-1) answer++;
            else{
                st.set(t,0);
            }
        }
        return answer;
    }
};