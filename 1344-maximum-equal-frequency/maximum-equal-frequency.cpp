class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> freq; // Frequency of each element
        map<int, int> count; // Count of each frequency
        int maxLen = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int num = nums[i];

            // Decrease count of current frequency
            if (freq[num] > 0) {
                count[freq[num]]--;
                if (count[freq[num]] == 0) {
                    count.erase(freq[num]);
                }
            }

            // Update frequency of the number
            freq[num]++;
            count[freq[num]]++;

            // Check if current prefix satisfies conditions
            int maxFreq = count.rbegin()->first;
            int minFreq = count.begin()->first;

            if (count.size() == 1) {
                // All elements have the same frequency
                if (maxFreq == 1 || count[maxFreq] == 1) {
                    maxLen = i + 1;
                }
            } else if (count.size() == 2) {
                // Two different frequencies
                if (minFreq == 1 && count[minFreq] == 1) {
                    maxLen = i + 1;
                } else if (maxFreq == minFreq + 1 && count[maxFreq] == 1) {
                    maxLen = i + 1;
                }
            }
        }

        return maxLen;
    }
};
