class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for(int i = 0;i<n;i++){
            dp[i][i] = true;
        }
        char ch = s[0];
        string answer;
        answer+=ch;
        for(int i = 0;i<n-1;i++){
            if(s[i]==s[i+1]){
               dp[i][i+1] = true;
              
               answer = s.substr(i,2);
            }
        }

        for (int len = 3; len <= n; len++) {
            for(int i = 0;i<=n-len;i++){
               int j = i + len - 1;
               if(s[i]==s[j]&&dp[i + 1][j - 1]){
                    answer = s.substr(i,len);
                    dp[i][j] = true;
               }
            }
        }
       
        return answer;

    }
};