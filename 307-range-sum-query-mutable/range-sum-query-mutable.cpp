class NumArray {
public:
    struct segtree {
        int size;
        vector<int> sums;
        void init(int n) {
            size = 1;
            while (size < n) size *= 2;
            sums.assign(2 * size, 0LL);
        }

        long long sum(int l, int r, int x, int lx, int rx) {
            if (lx >= r || l >= rx) return 0;
            if (lx >= l && rx <= r) return sums[x];
            
            int mid = (lx + rx) / 2;
            long long s1 = sum(l, r, 2 * x + 1, lx, mid);
            long long s2 = sum(l, r, 2 * x + 2, mid, rx);
            return s1+s2;
        }

        long long sum(int l, int r) {
            return sum(l, r, 0, 0, size);
        }

        void build(vector<int>& a){
            build(a,0,0,size);
        }
        void build(vector<int> &a,int x,int lx,int rx){
            if(rx-lx==1) {
                if(lx<(int)a.size()){
                    sums[x] = a[lx];
                }
                return;
            }
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
            sums[x] = sums[2*x+1]+sums[2*x+2];
        }
        void set(int i, int v, int x, int lx, int rx) {
            if (rx - lx == 1) {
                sums[x] = v;
                return;
            }

            int mid = (lx + rx) / 2;
            if (i < mid) {
                set(i, v, 2 * x + 1, lx, mid);
            } else {
                set(i, v, 2 * x + 2, mid, rx);
            }
            sums[x] =(sums[2 * x + 1]+sums[2 * x + 2]);
        }

        void set(int i, int v) {
            set(i, v, 0, 0, size);
        }
    };

    segtree st;
    int sz;
    NumArray(vector<int>& nums) {
        st.init(nums.size());
        st.build(nums);
        sz=nums.size();
    }
    
    void update(int index, int val) {
        st.set(index,val);
    }
    
    int sumRange(int left, int right) {
        int answer = (int)st.sum(left,right+1);
        return answer;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */