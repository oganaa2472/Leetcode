class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false)); // Палиндром эсэхийг хадгалах DP хүснэгт
        vector<int> dp(n, 0);
        
       
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    isPal[i][j] = (len == 1 || len == 2) ? true : isPal[i + 1][j - 1];
                }
            }
        }
         for (int i = 0; i < n - 2; i++) {
            if (isPal[0][i]) { 
                for (int j = i + 1; j < n - 1; j++) {
                    if (isPal[i + 1][j] && isPal[j + 1][n - 1]) { 
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};