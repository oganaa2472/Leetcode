class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> suff(n + 1, 0);
        long long sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (i + 1 < n && nums[i] <= nums[i + 1]) break;
            sum += nums[i];
            suff[i] = sum;
        }
        long long ans = LLONG_MAX;
        long long left = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] <= nums[i - 1]) break;
            left += nums[i];
            if (suff[i + 1] > 0) {
                ans = min(ans, abs(suff[i + 1] - left));
            }
        }
          return ans == LLONG_MAX ? -1 : ans;
    }
};