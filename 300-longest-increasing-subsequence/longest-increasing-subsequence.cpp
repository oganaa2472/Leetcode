class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
       int ansMax = 0;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            auto lower = lower_bound(ans.begin(),ans.end(),nums[i]);
            if(lower==ans.end()){
                ans.push_back(nums[i]);
            }else{
                ans[lower-ans.begin()]=nums[i];
            }
        }
       return ans.size();
    }
};