#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// less: it is the basic for comparison of two function. Use less_equal for ordered multiset.
// order_of_key(k): Number of items strictly smaller than k
// find_by_order(k): kth element in a set (counting from zero) 

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        oset<int> st;
        vector<int> ans;
        int n = nums.size();
        for(int i=n-1; i>=0; --i){
            ans.push_back(st.order_of_key(nums[i]));
            st.insert(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};