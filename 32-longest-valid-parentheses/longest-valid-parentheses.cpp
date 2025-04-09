class Solution {
public:
    int solve(string s){
        int n = s.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        for(int i =0;i<n;i++){
            if(s[i]=='(') left++;
            else right++;
            if(left==right){
                ans = max(ans,left*2);
            }else if(right>left) {
                left = 0;
                right = 0;
            }
        }
        return ans;
    }
    int solve1(string s){
        int n = s.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        for(int i =n-1;i>=0;i--){
            if(s[i]=='(') left++;
            else right++;
            if(left==right){
                ans = max(ans,left*2);
            }else if(right<left) {
                left = 0;
                right = 0;
            }
        }
        return ans;
    }
    int longestValidParentheses(string s) {
        
        int ans = solve(s);
       
        ans = max(ans,solve1(s));
        return ans;
    
    }
};