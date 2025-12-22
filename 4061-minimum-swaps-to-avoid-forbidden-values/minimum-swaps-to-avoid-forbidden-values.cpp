class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;
        for (int x : forbidden) mp[x]++;

        for (auto &p : mp) {
            if (p.second > n) return -1;
        }

        unordered_map<int, int> mp2;
        int total = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == forbidden[i]) {
                mp2[nums[i]]++;
                total++;
            }
        }

        if (total == 0) return 0;

        int maxSwaps = 0;
        for (auto &p : mp2) {
            maxSwaps = max(maxSwaps, p.second);
        }

        return max(maxSwaps, (total + 1) / 2);
    }
};