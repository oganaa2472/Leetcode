class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        unordered_map<int,vector<int>> memo;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i<n;i++){
            memo[i].push_back(nums[i]);
        }
        vector<int> dp(nums.size(),1);
        int maxi = 1;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i]>nums[j]&&nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i] = dp[j]+1;
                        if(dp[i]>maxi){
                            maxi=dp[i];
                        }   
                    }
                }
            }
        }
        vector<int> answer;
       int num = -1;
       for(int i = n-1;i>=0;i--){
        if(dp[i]==maxi&&(num==-1||num%nums[i]==0)){
            answer.push_back(nums[i]);
            maxi--;
            num = nums[i];
        }
       }
        return answer;
    }
};