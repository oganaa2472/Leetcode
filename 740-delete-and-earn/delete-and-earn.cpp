class Solution {
public:
    // void solve(int index,unordered_map<int,int> mp,vector<int>& num,int ans){
    //     if(index>=num.size()) return;
    //     int result = mp[num[index]]*num[index];
    //     if(mp.count(num[index]+1)>0) mp.erase(num[index]+1);
    //     if(mp.count(num[index]-1)>0) mp.erase(num[index]-1);
    //     solve(index+1,mp,num,ans);
    //     ans = max(ans,result);
        
    // }

    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(2e4+1,0);

        unordered_map<int,int> mp;
        for(auto n:nums){
            mp[n]++;
        }
        dp[1] = mp[1];

        for(int i = 2;i<dp.size();i++){
            dp[i] = max(dp[i-2]+mp[i]*i,dp[i-1]);
            // cout<<dp[i];
        }
    
        return dp[dp.size()-1];
    }
};