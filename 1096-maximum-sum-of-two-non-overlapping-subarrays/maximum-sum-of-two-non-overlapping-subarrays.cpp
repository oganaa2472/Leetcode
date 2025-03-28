class Solution {
public:
    int fun(int i,int k,int prev,int l1,int l2,vector<int> &nums, vector<vector<vector<int>>> &dp,vector<int> &prefix)
    {
        int n = nums.size();
        if (k == 0 || i == n)
        {
            return 0;
        }

        if (dp[i][k][prev+1] != -1)
        {
            return dp[i][k][prev+1];
        }

        int sum1 = 0;
        int maxi = 0;
        if ((prev == -1 || prev == 1) && i+l1<=n)
        {

            sum1 = prefix[i+l1]-prefix[i];

    

            int pick = sum1 + fun(i+l1,k-1,2,l1,l2,nums,dp,prefix);
            maxi = max(maxi,pick);
        }

        int sum2 = 0;
        if ((prev == 2 || prev == -1) && i+l2<=n)
        {
            
            sum2 = prefix[i+l2]-prefix[i];


            int pick = sum2 + fun(i+l2,k-1,1,l1,l2,nums,dp,prefix);
            maxi = max(maxi,pick);
        }
        int notpick = fun(i+1,k,prev,l1,l2,nums,dp,prefix);

        maxi = max(maxi,notpick);
        return dp[i][k][prev+1]=maxi;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<vector<vector<int>>> dp(nums.size()+1,vector<vector<int>>(3,vector<int>(4,-1)));
        int n = nums.size();
        vector<int> prefix(n+1,0);
        prefix[0] = 0;
        for (int i = 1;i<=n;i++)
        {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        return fun(0,2,-1,firstLen,secondLen,nums,dp,prefix);
    }
};