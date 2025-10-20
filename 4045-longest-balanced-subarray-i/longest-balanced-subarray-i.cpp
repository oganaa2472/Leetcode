#include <bits/stdc++.h>
using namespace std;

struct Node {
    int mn;     // minimum in the segment
    int mx;     // maximum in the segment
    int lazy;   // lazy propagation value

    Node(int _mn = INT_MAX, int _mx = INT_MIN, int _lazy = 0)
        : mn(_mn), mx(_mx), lazy(_lazy) {}
};

struct LazySegmentTree {
    int n;
    vector<Node> tree;

    LazySegmentTree(vector<int>& a) {
        n = a.size();
        tree.assign(4*n, Node());
        build(a,1,0,n-1);
    }

    void build(vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(arr[l], arr[l], 0);
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);
        tree[node].mn = min(tree[2*node].mn, tree[2*node+1].mn);
        tree[node].mx = max(tree[2*node].mx, tree[2*node+1].mx);
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy != 0) {
            tree[node].mn += tree[node].lazy;
            tree[node].mx += tree[node].lazy;
            if (l != r) {
                tree[2*node].lazy += tree[node].lazy;
                tree[2*node+1].lazy += tree[node].lazy;
            }
            tree[node].lazy = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);
        if (r < ql || l > qr) return; // no overlap
        if (ql <= l && r <= qr) {     // complete overlap
            tree[node].lazy += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(2*node, l, mid, ql, qr, val);
        update(2*node+1, mid+1, r, ql, qr, val);
        tree[node].mn = min(tree[2*node].mn, tree[2*node+1].mn);
        tree[node].mx = max(tree[2*node].mx, tree[2*node+1].mx);
    }

    int queryMin(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (r < ql || l > qr) return INT_MAX;
        if (ql <= l && r <= qr) return tree[node].mn;
        int mid = (l + r) / 2;
        return min(queryMin(2*node, l, mid, ql, qr),
                   queryMin(2*node+1, mid+1, r, ql, qr));
    }

    int queryMax(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (r < ql || l > qr) return INT_MIN;
        if (ql <= l && r <= qr) return tree[node].mx;
        int mid = (l + r) / 2;
        return max(queryMax(2*node, l, mid, ql, qr),
                   queryMax(2*node+1, mid+1, r, ql, qr));
    }

    int right_most_zero(int v,int l, int r){
        push(v,l,r);
        if(tree[v].mn>0 || tree[v].mx<0) return -1;
        if(l==r) return l;
        int m = (l+r)/2;
        int res = right_most_zero(v*2+1,m+1,r);
        if(res!=-1) return res;
        return right_most_zero(v*2,l,m);
    }

    // Helper functions
    void build(vector<int>& arr) { build(arr, 1, 0, n-1); }
    void update(int l, int r, int val) { if(l<=r) update(1, 0, n-1, l, r, val); }
    int queryMin(int l, int r) { return queryMin(1, 0, n-1, l, r); }
    int queryMax(int l, int r) { return queryMax(1, 0, n-1, l, r); }
    int right_most_zero() { return right_most_zero(1, 0, n-1); }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        map<int,int> occ;
        vector<int> next_pos(n,n);

        for(int i = n-1;i>=0;i--){
            if(occ.count(nums[i])){
                next_pos[i] = occ[nums[i]];
            }
            occ[nums[i]] = i;
        }

        vector<int> prefix(n,0);
        unordered_set<int> unique;
        for(int i = 0;i<n;i++){
            if(i) prefix[i] += prefix[i-1];
            if(unique.count(nums[i])) continue;
            if(nums[i]%2==0) prefix[i]++;
            else prefix[i]--;
            unique.insert(nums[i]);
        }

        LazySegmentTree seg(prefix);
        int ans = seg.right_most_zero() + 1;

        for(int i = 1; i < n; i++){
            int r = next_pos[i-1]-1;
            int v = nums[i-1]%2==0 ? 1 : -1;
            if(r >= 0) seg.update(0, r, -v); // remove previous number
            ans = max(ans, seg.right_most_zero()-i+1);
        }
        return ans;
    }
};
