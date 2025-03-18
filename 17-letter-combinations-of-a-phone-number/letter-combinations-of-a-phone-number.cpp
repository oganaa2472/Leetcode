class Solution {
public:
    vector<string> answer;
    string digits;
    int n; 
    vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
   
    void solve(int i,string ans){
        if(i==n) {
            answer.push_back(ans);
            return;      
        }
        int index = digits[i]-'0';
  
        string digit = dict[index];
        for(auto ch:digit){
            ans.push_back(ch);
            solve(i+1,ans);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
      
        n = digits.size();
    

        if(n==0){
            return answer;
        }
        solve(0,"");
        return answer;
    }
};