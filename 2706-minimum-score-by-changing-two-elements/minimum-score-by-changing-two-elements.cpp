class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==3) return 0;
       int answer = nums[n-1] - nums[1];

answer = min({
    answer,
    nums[n-1] - nums[2],
    nums[n-2] - nums[0],
    nums[n-3] - nums[0],
    nums[n-2] - nums[1]
});
        return answer;
    }
};