class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int solve(int i,int mask,vector<int>&nums1, vector<int>& nums2){
        if(i==n)
            return 0;
        
        if(dp[i][mask]!=-1) return dp[i][mask];

        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {

            if((mask&(1<<j))==0) // checking this element choose or not 
            {
                int new_mask = mask | (1 << j); // chosen 
                ans = min(ans, (nums1[i] ^ nums2[j]) + solve(i + 1, new_mask, nums1, nums2));
            }
        }

        return dp[i][mask] = ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        int m = (1<<n);
        dp.assign(n,vector<int>(m,-1));

        return solve(0,0,nums1,nums2);
    }
};