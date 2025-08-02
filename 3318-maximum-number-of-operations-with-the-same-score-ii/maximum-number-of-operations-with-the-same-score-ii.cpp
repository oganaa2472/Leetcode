class Solution {
public:
    vector<vector<int>> dp;
    vector<int> nums;
    int solve(int i,int j,int cur){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return -1;
        if(cur==-1){
            int cur1 = 1+solve(i+2,j,nums[i]+nums[i+1]);
            int cur2 = 1+solve(i,j-2,nums[j]+nums[j-1]);
            int cur3 = 1+solve(i+1,j-1,nums[i]+nums[j]);
            return dp[i][j] = max({cur1,cur2,cur3});
        }else{
            int cur1 =nums[i]+nums[i+1];
            int cur2 = nums[j]+nums[j-1];
            int cur3 = nums[i]+nums[j];
            int a=0,b=0,c=0;
            if(cur1==cur){
                a=1+solve(i+2,j,cur1);
            }
            if(cur2==cur){
                b=1+solve(i,j-2,cur2);
            }
            if(cur==cur3){
                c=1+solve(i+1,j-1,cur3);
            }
            return dp[i][j] = max({a,b,c});
    }
}
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,vector<int>(n,-1));
        this->nums = nums;
        return solve(0,n-1,-1);
    }
};