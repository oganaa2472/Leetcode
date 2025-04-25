class Solution {
public:
    void updateBit(vector<int>& bit, int num, int delay) {
        for (int i = 0; i < 32; i++) {
            if ((1 << i) & num) {
                bit[i] += delay;
            }
        }
    }

    int calculate(vector<int>& bit) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (bit[i] >= 1) { // Optional: change to >= 1 for safety
                result |= (1 << i);
            }
        }
        return result;
    }

    bool hasValidSubarray(vector<int>& num, int k, int mid) {
        vector<int> bit(32, 0);
        int n = num.size();
        for (int right = 0; right < n; right++) {
            updateBit(bit, num[right], 1);
            if (right >= mid) {
                updateBit(bit, num[right - mid], -1);
            }
            if (right >= mid - 1 && calculate(bit) >= k) {
                return true;
            }
        }
        return false;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left = 1;
        int right = nums.size();
        int minLength = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (hasValidSubarray(nums, k, mid)) {
                minLength = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return minLength;
    }
};
