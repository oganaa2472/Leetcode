class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        long long total = 1LL * k * (mx - mn);
        return total;

    }
};