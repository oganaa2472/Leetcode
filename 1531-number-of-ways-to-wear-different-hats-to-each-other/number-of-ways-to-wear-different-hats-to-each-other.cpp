class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> dp;
    int n ;
   vector<vector<int>> hats;
    int solve(int mask,int cur){
        if(mask==(1<<n)-1) return 1;
        if (cur >= 41) return 0;  // No more hats available
        if(dp[mask][cur]!=-1) return dp[mask][cur];
        
        int num = solve(mask, cur + 1) % mod;
        for(int i = 0;i<hats[cur].size();i++){
            int person = hats[cur][i];
            if(!(mask&(1<<person))){
                num = (num + solve(mask | (1 << person), cur + 1)) % mod;
            }
        }
        return dp[mask][cur] = num;
    }
    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        dp.resize((1<<n)+1,vector<int>(42,-1));
        this->hats = vector<vector<int>>(41);  // Prepare a hat-to-people mapping

        for (int i = 0; i < n; i++) {
            for (int hat : hats[i]) {
                this->hats[hat].push_back(i);  // People who can wear each hat
            }
        }

        return solve(0,0);
    }
};