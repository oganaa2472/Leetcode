class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++, end--;
        }
        return true;
    }
    vector<vector<string>> result;
    vector<string> current;
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
        backtrack(s, 0);
        return result;
    }
};