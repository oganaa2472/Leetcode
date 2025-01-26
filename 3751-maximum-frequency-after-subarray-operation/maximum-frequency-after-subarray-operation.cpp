class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int c = 0;
        for (int num : nums) {
            if (num == k) c++;
        }
        int gain = 0;
        for (int v = 1; v <= 50; ++v) {
            if (v == k) continue;
            
            int current_max = 0;
            int max_subarray = 0;
            for (int num : nums) {
                int val = (num == v) ? 1 : (num == k ? -1 : 0);
                current_max = max(val, current_max + val);
                max_subarray = max(max_subarray, current_max);
            }
            gain = max(gain, max_subarray);
        }
        
        return c + gain;
    }
};