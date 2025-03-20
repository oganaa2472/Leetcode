class Solution {
public:
    vector<vector<long long>> dp;
    vector<int> nums;
    int n ;
    long long solve(int i,int even){
        if(i==n) return 0;
        if(dp[i][even]!=-1) return dp[i][even];
        // int ans = INT_MIN;
        if (even) {
          
            return dp[i][even] = max(nums[i] + solve( i + 1, false), solve(i + 1, true));
        } else {
        
            return dp[i][even] = max(-nums[i] + solve( i + 1, true), solve( i + 1, false));
        }

    }
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        dp.resize(n+1,vector<long long>(3,-1));
        this->nums= nums;
        return solve(0,1);
        
    }
};