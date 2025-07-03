class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int b = 0; b < 32; b++) {
            int x = 0, y = 0;
            int mask = 1 << b;
            for (int num : nums) {
                if (num & mask) {
                    x++;
                }
            }
            for (int num = 1; num < n; num++) {
                if (num & mask) {
                    y++;
                }
            }
            if (x > y) {
                res |= mask;
            }
        }
        return res;
    }
};