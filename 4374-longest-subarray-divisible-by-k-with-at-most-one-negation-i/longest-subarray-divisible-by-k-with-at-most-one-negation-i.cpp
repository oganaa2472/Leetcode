
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for (int l = 0; l < n; l++) {
            long long sum = 0;
            unordered_set<int> seen;

            for (int r = l; r < n; r++) {
                sum += nums[r];

                int rem = ((sum % k) + k) % k;
                int x = ((2LL * nums[r] % k) + k) % k;

                seen.insert(x);

                // Нөхцөл 1: Нийлбэр k-д хуваагдана
                if (rem == 0) {
                    ans = max(ans, r - l + 1);
                }

                // Нөхцөл 2: Нэг элементийн тэмдгийг өөрчилж болно
                if (seen.count(rem)) {
                    ans = max(ans, r - l + 1);
                }
            }
        }

        return ans;
    }
};
