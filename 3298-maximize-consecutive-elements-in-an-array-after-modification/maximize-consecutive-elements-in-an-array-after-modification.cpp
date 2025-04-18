class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
    }

    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        sort(nums.begin(), nums.end());
        map<int, int> DP;

        for (int i = 0; i < n; i++) {
            int a = 1, b = 1;

            if (DP.find(nums[i] - 1) != DP.end()) {
                a = DP[nums[i] - 1] + 1;
            }
            
            if (DP.find(nums[i]) != DP.end()) {
                b = DP[nums[i]] + 1;
            }
            
            if (DP.find(nums[i]) == DP.end()) DP[nums[i]] = a; else DP[nums[i]] = max(DP[nums[i]], a);
            if (DP.find(nums[i] + 1) == DP.end()) DP[nums[i] + 1] = b; else DP[nums[i] + 1] = max(DP[nums[i] + 1], b);
            
            ans = max(max(DP[nums[i]], DP[nums[i] + 1]), ans);
        }
        
        return ans;
    }
};