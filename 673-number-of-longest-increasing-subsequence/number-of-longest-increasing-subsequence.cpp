class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);

        vector<int> count(n,1);
        int ans = 1;
        for(int i = 1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i]<dp[j]+1){
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }else
                    if(dp[i]==dp[j]+1){
                        count[i] += count[j];
                    }
                }
                
            }
            ans = max(dp[i],ans);
        }
        int result = 0;
      
        for (int i = 0; i < n; i++) {
            cout<<count[i]<<" ";
            if (dp[i] == ans) {
                result += count[i];
            }
        }
        return result;
    }
};