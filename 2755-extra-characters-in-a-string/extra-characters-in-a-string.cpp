class Solution {
public:
    unordered_map<string,int> memo;
    int solve(string s,unordered_set<string>& word){
        int n = s.size();

        if(s.empty()) return 0; 
        if(memo.count(s)) return memo[s];
        int res = INT_MAX;
        string first = "";

        for(int i = 0;i<n;i++){
            first+=s[i];
            res = min(res,(int)first.size()+solve(s.substr(i+1),word));
            if(word.count(first)){
                res= min(res,solve(s.substr(i+1),word));
            }
        }
        return memo[s] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> word(dictionary.begin(),dictionary.end());

        return solve(s,word);
        
    }
};