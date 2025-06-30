class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int l = 0;
        int answer = INT_MAX;
        for(int r = 0;r<nums.size();r++){
            sum += nums[r];
            
         
            while(sum>=target){
                answer = min(answer,r-l+1);
                sum -=nums[l];
                l++;
            }
            
        }
        return answer==INT_MAX?0:answer;
    }
};