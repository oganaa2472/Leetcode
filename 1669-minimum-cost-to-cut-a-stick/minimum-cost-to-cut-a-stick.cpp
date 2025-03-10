class Solution {
public:
  
    // Base case: If i is greater than j, there are no cuts to consider.
int dp[102][102] = {};
vector<int> cuts;
int dfs(int i, int j) {
    if (j - i <= 1)
        return 0;
    if (!dp[i][j]) {
        dp[i][j] = INT_MAX;
        for (auto k = i + 1; k < j; ++k)
            dp[i][j] = min(dp[i][j], 
                cuts[j] - cuts[i] + dfs(i, k) + dfs( k, j));
    }
    return dp[i][j];
}
int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(begin(cuts), end(cuts));
    this->cuts = cuts;
    return dfs(0, cuts.size() - 1);
}
};