class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_set<int> st;
        int n = nums.size();
        set<long long> window; 

        for (int i = 0; i < n; i++) {
            auto it = window.lower_bound((nums[i])-valueDiff);
            if (it!=window.end()&&*it-nums[i]<=valueDiff) {
                return true;
            }
            window.insert(nums[i]);

           
            if (i >= indexDiff) {
                window.erase(nums[i - indexDiff]);
            }
        }
        return false;
    }
};