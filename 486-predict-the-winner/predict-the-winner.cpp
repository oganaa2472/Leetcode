class Solution {
public:

// minimal dp same algorith with stone game 1
    vector<vector<int>> dp;
    vector<int> nums;

    int n;

    int solve(int left,int right){
        if(left>right){
            return 0;
        }
        if(dp[left][right]!=-1) dp[left][right];


        int chooseFirst =nums[left]-solve(left+1,right);
        int chooseLast = nums[right]-solve(left,right-1);

        return dp[left][right] = max(chooseFirst,chooseLast);
    }
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        this->nums=nums;
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,n-1)>=0;
    }
};