class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) return 1.0; 
        if (N >= K + W - 1) return 1.0; 

        vector<double> dp(N + 1, 0.0);
        dp[0] = 1.0;
        double sumWindow = 1.0, result = 0.0;
        for (int i = 1; i <= N; i++) {
            dp[i] = sumWindow / W;

            if (i < K) sumWindow += dp[i]; 
            else result += dp[i]; 

            if (i >= W) sumWindow -= dp[i - W]; 
        }

        return result;
    }
};
