class Solution {
public:
    int n ;
    vector<vector<int>> piles;

    vector<vector<int>> dp;
    int solve(int i,int k){
        if(i==n||k==0){
            return 0;
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int exclude = solve(i+1,k);
        int currentSum = 0;
        int ans = INT_MIN;
        for(int j = 0;j<min(k,(int)piles[i].size());j++){
            currentSum += piles[i][j];
            ans=max(ans,currentSum+solve(i+1,k-(j+1)));
        }

        return dp[i][k] = max(ans,exclude);

    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        this->piles=piles;
        n = piles.size();
        dp.assign(piles.size(), vector<int>(k + 1, -1));
        return solve(0,k);
    }
};