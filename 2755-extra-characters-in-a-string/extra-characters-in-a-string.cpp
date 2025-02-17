class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int,int> dp;
    int n;
    string s;
    int solve(int start){
        if(start==n) return 0;
        if(dp.count(start)) return dp[start];
        int ans=solve(start+1)+1;
         for (int i = start; i < n; i++) {
                string curr = s.substr(start, i - start + 1);
            if (dict.count(curr)) {
                ans = min(ans, solve(i + 1));
            }
        }
        return dp[start] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();
        this->s=s;
        for(auto& d:dictionary){
            dict.insert(d);
        }
        return solve(0);
    }
};