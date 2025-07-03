class Solution {
public:
    
    vector<int> nums;
    int solve(int i,int even,vector<vector<int>>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i][even]!=-1) return dp[i][even];
        int not_take = solve(i+1,even,dp);
        int take = 0;
        if((nums[i]%2==0&&even==false)||(nums[i]%2!=0&&even == true) ){
            take = 1+solve(i+1,nums[i]%2==0,dp); 
        }   
        return dp[i][even] = max(not_take,take);
    }
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        vector<vector<int>> dp(nums.size()+1,vector<int>(2,-1));
       int odd=0;
        for(int i = 0;i<n;i++){
            if(nums[i]%2==1) odd++;
        }
        return max({solve(0,false,dp),solve(0,true,dp),odd,n-odd});
    }
};