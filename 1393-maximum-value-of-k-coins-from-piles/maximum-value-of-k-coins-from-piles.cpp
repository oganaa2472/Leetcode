class Solution {
public:
    int n;
    vector<vector<int>> piles;
    vector<vector<int>> dp;
    int solve(int i,int k){
        if(i==n || k == 0){
            return 0;
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int exclude = solve(i+1,k);
        int currentSum = 0;
        for(int j = 0;j<min((int)piles[i].size(), k);j++){
            currentSum += piles[i][j];
            exclude = max(exclude,currentSum+solve(i+1,k-j-1));
        }

        return dp[i][k] = exclude;

    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        this->piles=piles;
        
        dp.assign(n, vector<int>(k + 1, -1));
        return solve(0,k);
    }
};