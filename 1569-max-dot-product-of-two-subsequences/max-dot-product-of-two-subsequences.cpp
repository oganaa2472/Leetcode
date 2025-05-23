class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1000000));
    
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                int a = nums1[i-1]*nums2[j-1];
                dp[i][j] = max({dp[i-1][j],dp[i][j-1],a+dp[i-1][j-1],a});
            }
        }
        return dp[n][m];
    }
};