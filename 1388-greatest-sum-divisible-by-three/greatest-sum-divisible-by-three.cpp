class Solution {
public:
    int ans = 0;

    int solve(int index,int pos, vector<int>& nums,vector<vector<int>>& memo){
        if(index>=nums.size()){
        if(pos==0){
            return 0;
        }
        return INT_MIN;
    }
        // Check if the result is already computed for (sum, index);
        if (memo[index][pos%3] != -1) {
            return memo[index][pos%3];
        }


        int include =nums[index]+solve(index+1, (pos+nums[index])%3, nums, memo);
        int exclude = solve(index+1, pos, nums, memo);

        return memo[index][pos] = max(include,exclude);
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(),vector<int>(3,-1));

        return solve(0,0,nums,memo);
     }
};