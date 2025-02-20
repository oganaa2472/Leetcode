class Solution {
public:
    int minCut(string s) {
        int n = s.size();
      

        vector<vector<bool>> isPal(n, vector<bool>(n, false)); // Палиндром эсэхийг хадгалах DP хүснэгт
        vector<int> dp(n, 0); // dp[i] - s[0:i] хамгийн бага хуваалт
        
      
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    isPal[i][j] = (len == 1 || len == 2) ? true : isPal[i + 1][j - 1];
                }
            }
        }
        // for(int i = 0;i<n;i++){

        //     for(int j = 0;j<n;j++){
        //         cout<<isPal[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans = n;

        for(int i = 0;i<n;i++){
            if(isPal[0][i]) dp[i] = 0;
            else{

                dp[i] = i;
                for (int j = 0; j < i; j++) {
                    if (isPal[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return dp[n-1];
    }
};