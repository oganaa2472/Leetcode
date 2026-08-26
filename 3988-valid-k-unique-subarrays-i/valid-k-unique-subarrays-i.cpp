#include <vector>
#include <unordered_map>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

// Завсар дахь < l байх элементүүдийн тоог O(log N)-д тоолох Merge Sort Tree
struct MergeSortTree {
    int n;
    vector<vector<int>> tree;

    MergeSortTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        if (n > 0) build(0, 0, n - 1, arr);
    }

    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[node] = {arr[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node + 1, start, mid, arr);
        build(2 * node + 2, mid + 1, end, arr);
        
        tree[node].resize(tree[2 * node + 1].size() + tree[2 * node + 2].size());
        merge(tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
              tree[2 * node + 2].begin(), tree[2 * node + 2].end(),
              tree[node].begin());
    }

    // [l, r] завсарт утга нь < val байх элементүүдийн тоо
    int queryLessThan(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) {
            return lower_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
        }
        int mid = start + (end - start) / 2;
        return queryLessThan(2 * node + 1, start, mid, l, r, val) +
               queryLessThan(2 * node + 2, mid + 1, end, l, r, val);
    }

    int countDistinct(int l, int r) {
        return queryLessThan(0, 0, n - 1, l, r, l);
    }
};

class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        
        // 1. Утга бүрд санамсаргүй 64-бит тоо оноох (Zobrist Hashing)
        mt19937_64 rng(1337);
        unordered_map<int, unsigned long long> val_hash;
        for (int x : nums) {
            if (val_hash.find(x) == val_hash.end()) {
                val_hash[x] = rng();
            }
        }

        // 2. Prefix XOR бэлдэх
        vector<unsigned long long> pref_xor(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref_xor[i + 1] = pref_xor[i] ^ val_hash[nums[i]];
        }

        // 3. Өмнөх тохиолдсон байршлыг (last_pos) олох
        vector<int> prev_pos(n, -1);
        unordered_map<int, int> last_seen;
        for (int i = 0; i < n; ++i) {
            if (last_seen.count(nums[i])) {
                prev_pos[i] = last_seen[nums[i]];
            }
            last_seen[nums[i]] = i;
        }

        // 4. Merge Sort Tree байгуулах
        MergeSortTree mst(prev_pos);

        // 5. Query бүрийг боловсруулах
        vector<bool> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int len = r - l + 1;

            // Хэрэв завсрын урт сондгой эсвэл 2*k-аас бага бол шууд false
            if (len % 2 != 0 || len < 2 * k) {
                ans.push_back(false);
                continue;
            }

            // Нөхцөл 1: Бүх элементүүд тэгш давтамжтай эсэх
            if ((pref_xor[r + 1] ^ pref_xor[l]) != 0) {
                ans.push_back(false);
                continue;
            }

            // Нөхцөл 2: Яг k ялгаатай тоо байгаа эсэх
            int distinct_count = mst.countDistinct(l, r);
            ans.push_back(distinct_count == k);
        }

        return ans;
    }
};