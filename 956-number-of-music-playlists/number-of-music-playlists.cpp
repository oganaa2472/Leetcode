class Solution {
public:

    int mod = 1e9+7;
    int n;
    int goal;
    int k;
    vector<vector<long long>> dp;
     long long solve(int i,int uniqSongs){
        if(i==goal) return uniqSongs==n;
        if(dp[i][uniqSongs]!=-1) return dp[i][uniqSongs];
        long long ans = 0;
        if(uniqSongs<n){
            ans = (ans + (n-uniqSongs)*solve(i+1,uniqSongs+1))%mod;
        }
        if(uniqSongs>k){
            ans = (ans + (uniqSongs-k)*solve(i+1,uniqSongs))%mod;
        }
        return dp[i][uniqSongs] = ans;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        
        this->goal=goal;
        this->n= n;
        this->k = k;
        dp.resize(goal+1,vector<long long>(n+1,-1));
        return  (int)solve(0,0);
    }
};