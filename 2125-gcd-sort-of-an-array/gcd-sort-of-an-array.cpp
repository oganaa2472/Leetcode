#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

// Factorize number
vector<int> primeFactors(int x) {
    vector<int> factors;
    for (int p = 2; p * p <= x; p++) {
        if (x % p == 0) {
            factors.push_back(p);
            while (x % p == 0) x /= p;
        }
    }
    if (x > 1) factors.push_back(x);
    return factors;
}


class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        DSU dsu(maxVal + 1);

        for (int x : nums) {
            auto factors = primeFactors(x);
            for (int f : factors) {
                dsu.unite(x, f);
            }
        }
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < n; i++) {
            if (dsu.find(nums[i]) != dsu.find(sorted[i])) {
                return false;
            }
        }
        return true;
    }
};