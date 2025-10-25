const int MOD = 1e9 + 7;
class Solution {
public:
    int n ,m;
    unordered_map<int,unordered_map<int,int>> dp;
    int solve(int row, int cur_gcd,vector<vector<int>>& mat){
        if(row == n){
            return cur_gcd == 1 ? 1: 0;
            
        }
        if(dp[row].count(cur_gcd)) return dp[row][cur_gcd];
        int ways = 0;
        for(int val:mat[row]){
            int new_gcd = __gcd(cur_gcd,val);
            ways = (ways + solve(row+1,new_gcd,mat)) % MOD;
        }
        return dp[row][cur_gcd] = ways;
    }
    int countCoprime(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        dp.clear();
        return solve(0,0,mat);
    }
};