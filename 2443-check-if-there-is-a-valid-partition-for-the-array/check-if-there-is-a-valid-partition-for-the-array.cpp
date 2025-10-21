
class Solution {
public:
    unordered_map<int,int> dp;
    int solve(int i,vector<int>& nums){

        int n = nums.size();
        if(i==n){
            return true;
        }
        if(dp.count(i)) return dp[i];
        int answer = false;
        if(i+1<n&&nums[i]==nums[i+1]){
            answer |= solve(i+2,nums);
        }
        if(i+2<n){
            if(nums[i]==nums[i+1]&&nums[i]==nums[i+2]){
                answer |= solve(i+3,nums);
            }else if(nums[i+2]-nums[i+1]==1&&nums[i+1]-nums[i]==1){
                answer|=solve(i+3,nums);
            }
        }
        return dp[i]=answer;
    }
    bool validPartition(vector<int>& nums) {
        return solve(0,nums);
    }
};