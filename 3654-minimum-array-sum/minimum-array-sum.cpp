class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<int> nums;
    int n;

    int solve(int i,int o1,int o2,int k){
        if(i==n) return 0;

        if(dp[i][o1][o2]!=-1) return dp[i][o1][o2];
        int ans = nums[i]+ solve(i+1,o1,o2,k);
        if(o1>0){
            int t = (nums[i]+1)/2;
            ans = min(ans,(t + solve(i+1,o1-1,o2,k)));
        }
        if(o2>0&&nums[i]>=k){
            ans = min(ans,(nums[i]-k + solve(i+1,o1,o2-1,k)));
        }
        if(o2>0&&o1>0&&nums[i]>=k){
            int t = (nums[i]+1)/2;
            if(t>=k){
                ans = min(ans,((t-k)+ solve(i+1,o1-1,o2-1,k)));
            }else{
                int tt = nums[i] - k;
                ans = min(ans,((tt+1)/2+ solve(i+1,o1-1,o2-1,k)));
            }

        }
        return dp[i][o1][o2] = ans;


    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        // we have given an integer array nums and three k,op1 and op2
        // we can perform the following operation
        // op 1 choose an index i and divid nums[i] by 2, rounded up to nearest whole number,you can 
        // at most op1 times and more than once per index 
        // operation 2 choose an index i and subtract k from nums[i], but only if nums[i] is greater than or
        // equal to k. we can perform this operation at most op2 times, and not more than once per index,
        // Both operations can be applied to the same index, but at most once
        // return the minimum possible sum of all elements in but after performing any number of operations.
        // nums [2,8,3,19,3] k = 3, op1 = 1 ,op2 = 1; 
        n = nums.size();
        dp.resize(nums.size()+1,vector<vector<int>>(op1+1,vector<int>(op2+1,-1)));
        this->nums = nums;
        return solve(0,op1,op2,k);
        
    }
};