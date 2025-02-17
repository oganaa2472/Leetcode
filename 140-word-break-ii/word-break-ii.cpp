class Solution {
public:
    unordered_set<string> dict;
    vector<string> answer;
    unordered_map<string,bool> dp;
    int n;
    void solve(int index,string& s,string& curstr){
        if(index==n){
            answer.push_back(curstr);
            return;
        }
        for (int i = index + 1; i <= s.size();
             ++i) {
            string word = s.substr(index, i - index);
            if (dict.find(word) != dict.end()) {
                string orig = curstr;
                if (!curstr.empty()) curstr += " ";
                curstr += word;
                
                solve(i,s,curstr);
              
                curstr = orig;
            }
        }
        

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(auto& word:wordDict){
            dict.insert(word);
        }
        string curstr;
        solve(0,s,curstr);
        return answer;

    }
};