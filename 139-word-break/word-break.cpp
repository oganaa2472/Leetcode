class Solution {
public:
    unordered_set<string> word;
    int n,m;
    // vector<int> dp;
    unordered_map<string,bool> dp;
    bool solve(string newstr){
       
        if(newstr.empty()) return true;
       if (dp.find(newstr) != dp.end()) return dp[newstr]; 
       

        for(int j=1;j<=newstr.size();j++){
            string fi = newstr.substr(0,j);
            string se = newstr.substr(j);
            if(word.count(fi)&&solve(se)){
                return dp[newstr] = true;
            }
        }
    
       
       
        return dp[newstr] =false;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        m = wordDict.size();
        for(int i = 0;i<m;i++)
        {
            word.insert(wordDict[i]);
        }
        return solve(s);
    }
};