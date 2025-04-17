class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector <int> dp(1000002,0);
        for(auto num:nums) {
            dp[num+1]=1+dp[num];
            dp[num]=max(dp[num],1+dp[num-1]);
        }
        return *max_element(begin(dp),end(dp));
    }
};