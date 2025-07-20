#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    unordered_map<long long, int> dp;

    int popCount(long long x) {
        if (x == 1)
            return 0;
        if (dp.count(x))
            return dp[x];
        int cnt = __builtin_popcountll(x);
        return dp[x] = 1 + popCount(cnt);
    }

    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        int n = (int)nums.size();
        vector<ordered_set<int>> v(10);

        for (int i = 0; i < n; i++) {
            v[popCount(nums[i])].insert(i);
        }
        
        vector<int> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int l = (int)q[1], r = (int)q[2], k = (int)q[3];
               
                ans.push_back(v[k].order_of_key(r+1)-v[k].order_of_key(l));
                
            } else {
                int idx = (int)q[1];
                long long val = q[2];
                v[popCount(nums[idx])].erase(idx);
                nums[idx] = val;
                v[popCount(nums[idx])].insert(idx);
                
            }
        }
        return ans;
    }
};
