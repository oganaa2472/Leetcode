class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k , vector<int>(k , 0));
        int maxi = 1;
        for(int num : nums){
            int currNum = num % k;
            for(int mod = 0 ; mod < k ; mod++){
                  int prevNum = (mod - currNum + k) % k;
                  dp[currNum][mod] = max(dp[currNum][mod] , 1 + dp[prevNum][mod]);
                  maxi = max(maxi , dp[currNum][mod]);
            }
        }
        return maxi;
    }
};