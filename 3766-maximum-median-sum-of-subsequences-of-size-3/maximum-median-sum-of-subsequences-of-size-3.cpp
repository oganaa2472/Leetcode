class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        int n = nums.size();
        int j = n-2;
        for(int i = 0;i<n/3;i++){
            ans+=nums[j];
            j=j-2;
        }
        return ans;
    }
};