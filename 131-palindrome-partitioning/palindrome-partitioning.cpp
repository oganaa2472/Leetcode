class Solution {
public:

    vector<vector<string>> result;
    bool isPalindrome(string &s, int start, int end) {
       
        while (start < end) {
            if (s[start] != s[end])  return false;
            start++, end--;
        }
        return true;
    }

    void solve(string s,int i,vector<string>& current){
        if(i==s.size()){
            result.push_back(current);
            return;
        }
        for(int j = i;j<s.size();j++){
            if(isPalindrome(s, i, j)){
                current.push_back(s.substr(i, j-i + 1));
                solve(s, j + 1,current);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        int n = s.size();
        vector<string> current;
        solve(s,0,current);
        return result;
    }
};