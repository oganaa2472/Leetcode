class Solution {
public:
    unordered_map<string,int> dp;
    bool isValid(string s){
        stack<char> st;
        for(auto& ch:s){
            if(ch=='(') st.push(ch);
            else{
                if(st.empty()) return false;
                else{
                    st.pop();
                }
            }
        }
        return st.size()==0?true:false;
    }
    int solve(int left,int right,string s){
        if(left==right) return 0;
         string key = to_string(left)+',' + to_string(right);
         string cur = s.substr(left,right-left+1);
        if(isValid(cur)) return dp[key] =  cur.size();
       
        if(dp.count(key)) return dp[key];
       
        
        int l = solve(left+1,right,s);
        int r = solve(left,right-1,s);
        return dp[key] = max(l,r);
    }
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        int ans = 0;
        for(int i = 1;i<n;i++){
            if(s[i]==')'){
                if(s[i-1]=='(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                else if(i - dp[i - 1] > 0&&s[i - dp[i - 1] - 1] == '('){
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};