
class Solution {
public:
    bool check(unordered_map<long long, int>& freq, long long x) {
        for (auto& [a, cnt] : freq) {
            // Case 1: a + b = x
            long long b = x - a;

            if (freq.count(b)) {
                if (a != b || cnt >= 2) {
                    return true;
                }
            }

            // Case 2: a + x = b
            b = a + x;

            if (freq.count(b)) {
                if (a != b || cnt >= 2) {
                    return true;
                }
            }
        }

        return false;
    }

    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int ans = 0;

        unordered_map<long long, int> freq;

        for (int right = 0; right < n; right++) {
            long long x = nums[right];

            while (check(freq, x)) {
                freq[nums[left]]--;

                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }

                left++;
            }

            freq[x]++;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
