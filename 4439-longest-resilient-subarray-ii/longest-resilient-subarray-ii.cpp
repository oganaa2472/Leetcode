class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; ) {
            int r = ((nums[i] % k) + k) % k;
            int j = i;

            while (j < n &&
                   ((nums[j] % k) + k) % k == r) {
                j++;
            }

            int len = j - i;

            if (r == 0) {
                ans = max(ans, len);
            } else {
                int need = k / gcd(k, r);
                int candidate = (len - 1) / need * need + 1;
                ans = max(ans, candidate);
            }

            i = j;
        }

        return ans;
    }
};