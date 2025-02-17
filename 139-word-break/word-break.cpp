class Solution {
public:
    int n;
    unordered_set<string> dict;
    unordered_map<string,bool> dp;
    bool solve(string s){
        if(s.empty()) return true;
        if (dp.find(s) != dp.end()) return dp[s]; 
        for(int i = 1;i<=s.size();i++){
            string firstHalves = s.substr(0,i);
            string secondHalves = s.substr(i);

            if(dict.count(firstHalves)&&solve(secondHalves)){
                return dp[s] = true;
            }
        }
        return dp[s] = false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(auto& word:wordDict){
            dict.insert(word);
        }
        return solve(s);
    }
};