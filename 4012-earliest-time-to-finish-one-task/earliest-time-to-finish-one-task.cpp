class Solution {
public:
    int earliestTime(vector<vector<int>>& nums) {
        int mi = INT_MAX;
        for(int i=0;i<nums.size();i++) mi = min(mi,nums[i][0]+nums[i][1]);
        return mi;
    }
};