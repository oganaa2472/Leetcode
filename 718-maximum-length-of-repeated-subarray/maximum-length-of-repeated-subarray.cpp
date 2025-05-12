class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,vector<int>&nums1,vector<int>&nums2){
        if(i==0||j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(nums1[i-1]==nums2[j-1]){
            return dp[i][j] = 1+solve(i-1,j-1,nums1,nums2);
        }
        else{
             return dp[i][j] = 0;
        }
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        dp.resize(n+1,vector<int>(m+1,0));
        int ans = 0;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    ans=max(dp[i][j],ans);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};