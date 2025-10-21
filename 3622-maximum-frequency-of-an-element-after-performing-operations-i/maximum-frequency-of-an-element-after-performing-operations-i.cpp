class Solution {
public:
  
int maxFrequency(vector<int>& nums, int k, int operations) {
    int maxVal = *max_element(nums.begin(), nums.end());
    int n = maxVal + k + 2;
    vector<int> freq(n, 0);
    
    for (int num : nums) {
        freq[num] += 1;
    }

    vector<int> prefixSum(n, 0);
    prefixSum[0] = freq[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + freq[i];
    }

    int maxFreq = 0;

    for (int target = 0; target < n; ++target) {
        if (freq[target] == 0 && operations == 0) {
            continue;
        }

        int left = max(0, target - k);
        int right = min(n - 1, target + k);
        int totalRange = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
        int adjustments = totalRange - freq[target];
        int achievableFreq = freq[target] + min(operations, adjustments);

        maxFreq = max(maxFreq, achievableFreq);
    }

    return maxFreq;
}

   
};