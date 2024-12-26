class Solution {
public:
    int count=0;
    void solve(vector<int>& nums,int target,int sum,int index){
        
        if(index==nums.size()-1){
            if(sum-nums[index]==target) count++;
            if(sum+nums[index]==target) count++;
            return;
        }
        solve(nums,target,sum+nums[index],index+1);
        solve(nums,target,sum-nums[index],index+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       
        solve(nums,target,0,0);
        return count;
    }
};