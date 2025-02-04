class Solution {
public:
    int size ;
    vector<string> strs;
    vector<vector<vector<int>>> dp;

    int solve(int index,int m,int n){
        if(index==size){
            return 0;
        }
        if(dp[index][m][n]!=-1) return dp[index][m][n];

        
        int count_0 = count(strs[index].begin(), strs[index].end(), '0');
        int count_1 = strs[index].size() - count_0;
        int exclude = solve(index+1,m,n);
        if (m >= count_0 && n >= count_1) {
            // indclude other we can choose this values each of us zero and one
            exclude = max(exclude, 1 + solve(index + 1, m - count_0,n-count_1));
        }
        return dp[index][m][n] = exclude;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        size = strs.size();
        dp.resize(size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        this->strs = strs;
        return solve(0,m,n);
    }
};