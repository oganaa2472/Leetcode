class Solution {
public:
    int mod = 1e9 + 7; 
    unordered_map<int, int> dp; 

    int solve(int low, int high, int zero, int one, int len) {
       
        if (len > high) return 0;

       
        if (dp.find(len) != dp.end()) return dp[len];

        int count = (len >= low && len <= high) ? 1 : 0;

        count = (count + solve(low, high, zero, one, len + zero)) % mod;

        count = (count + solve(low, high, zero, one, len + one)) % mod;

        
        return dp[len] = count;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        return solve(low, high, zero, one, 0); 
    }
};
