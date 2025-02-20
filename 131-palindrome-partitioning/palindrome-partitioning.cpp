class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<string>> result;
    vector<string> current;
    bool isPalindrome(string &s, int start, int end) {
        if (dp[start][end] != -1) return dp[start][end]; 
        while (start < end) {
            if (s[start] != s[end])  return dp[start][end] = 0;
            start++, end--;
        }
        return dp[start][end] = 1;
    }

    void backtrack(string s,int i){
        if(i==s.size()){
            result.push_back(current);
            return;
        }
        for(int j = i;j<s.size();j++){
            if(isPalindrome(s, i, j)){
                current.push_back(s.substr(i, j-i + 1));
                backtrack(s, j + 1);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));
        backtrack(s, 0);
        return result;
    }
};