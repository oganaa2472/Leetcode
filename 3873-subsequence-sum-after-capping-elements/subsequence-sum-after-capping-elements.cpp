class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(),nums.end());
        vector<bool> ans, dp(k + 1, false);
        dp[0] = true;
        int p = 0;
        for (int cap = 1; cap <= n; cap++) {
            int above_cap = 0;
            for(auto x:nums){
                if(x < cap) continue;
                if(x>cap) {above_cap++; continue;}

                for(int i = k;i>=x;i--)
                {
                    dp[i] = dp[i] | dp[i-x];
                }
            }

            bool pos = false;

            for(int i = k;i >= max(k-(cap*above_cap), 0); i =i-cap){
                pos = pos|dp[i];
            }
            ans.push_back(pos);
        }
        
        return ans;
    }
};