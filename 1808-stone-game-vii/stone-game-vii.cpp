class Solution {
public:

    // same solution with burst balloon
    vector<vector<int>> dp;
    int n;
    vector<int> prefixSum;
    vector<int> stones;
    int solve(int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int totalSum = prefixSum[j+1] - prefixSum[i];
        int first = totalSum - stones[i] - solve(i+1,j);
        int last = totalSum - stones[j] - solve(i,j-1);
        return dp[i][j] = max(first,last);
    }
    int stoneGameVII(vector<int>& stones) {
        n = stones.size();
        this->stones = stones;
        dp.resize(n,vector<int>(n,-1));
        prefixSum.resize(n+1,0);
        for(int i = 1;i<=n;i++){
            prefixSum[i] = prefixSum[i-1] + stones[i-1]; 
        }
       int answer = solve(0,n-1);
       return answer;
    }
};