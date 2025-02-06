class Solution {
public:
    vector<int> dp;
    string s;
    int n;
    int solve(int i){
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        string cur = s.substr(i,1);
       
        int ans = 0;
        if(cur>="1"&&cur<="9"){
            ans+=(solve(i+1));
        } 
       
        if(i<n-1){
            string cur2 = s.substr(i,2);
            if(cur2>="10"&&cur2<="26"){
                ans+=(solve(i+2));
            }
        }
       
        return dp[i] = ans;
    }

    int numDecodings(string s) {
        n = s.size();
        dp.resize(n,-1);
        this->s=s;
        return solve(0);
    }
};