class Solution {
public:
    int dp[2000][2000];
    unordered_map<int, int> m;
      bool solve(int i, int k, vector<int>& stones) {
        if (i == stones.size() - 1) {
            return true;
        }
        
        if (dp[i][k] != -1) {
            return dp[i][k];
        }
        bool k0 = false;
        bool kp = false;
        bool k1 = false;

        if (m.find(stones[i] + k) != m.end()) {
            k0 = solve(m[stones[i] + k], k, stones);
        }
        if (k > 1 && m.find(stones[i] + k - 1) != m.end()) {
            kp = solve(m[stones[i] + k - 1], k - 1, stones);
        }
        if (m.find(stones[i] + k + 1) != m.end()) {
            k1 = solve(m[stones[i] + k + 1], k + 1, stones);
        }

        dp[i][k] = k0 || kp || k1;
        return dp[i][k];
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
    
       
        for(int i = 0;i<n;i++){
            m[stones[i]] = i;
        }
        if (stones[1] - stones[0] != 1) {
            return false;
        }
        memset(dp, -1, sizeof(dp));

        return solve(1, 1, stones);
    }
};