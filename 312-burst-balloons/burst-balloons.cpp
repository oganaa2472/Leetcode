class Solution {
public:
    vector<vector<int>> dp;
    vector<int> nums;
    int solve(int i,int j){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int maxBalloons = 0;

       for (int k = i; k <= j; k++) {
            int coins = nums[i - 1] * nums[k] * nums[j + 1]; 
            int leftCoins = solve(i, k - 1); 
            int rightCoins = solve(k + 1, j); 
            
            maxBalloons = max(maxBalloons, leftCoins + coins + rightCoins);
        }
        return dp[i][j] = maxBalloons;
    }

    int maxCoins(vector<int>& nums) {
         int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        this->nums = nums;
        dp.resize(n+2,vector<int>(n+2,-1));

        return solve(1,n);

    }
};