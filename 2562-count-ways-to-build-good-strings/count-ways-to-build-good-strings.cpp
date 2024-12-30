class Solution {
public:
    int mod = 1e9+7;
    unordered_map<int,int> dp;

    int solve(int low,int high,int zero,int one,int len){
        if(len>high) return 0;
        if(dp.find(len)!=dp.end()) return dp[len];
    
       int res = (len >= low && len <= high) ? 1 : 0;
        res += (solve(low,high,zero,one,len + zero))+
            (solve(low,high,zero,one,len + one));
        return dp[len] = (res)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        return solve(low,high,zero,one,0);
    }
};