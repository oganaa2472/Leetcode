class Solution {
public:
    int n;
    vector<int> dp;

    bool solve(int i, string& s, int minJump, int maxJump) {
        if (i >= n - 1) return true;       
        if (dp[i] != -1) return dp[i];     
        for (int k = minJump; k <= maxJump; k++) {
            if (i + k < n && s[i + k] == '0' && solve(i + k, s, minJump, maxJump)) {
                return dp[i] = 1;         
            }
        }
        return dp[i] = 0;                  
    }

    bool canReach(string s, int minJump, int maxJump) {
        int cnt = 0;
      
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '1'){
                cnt++;
                if(cnt >= maxJump) return false;
            }
            else{
                cnt = 0;
            }
        }
        
        n = s.size();
        dp.resize(n, -1);
        if (s[n - 1] == '1') return false;  
        return solve(0, s, minJump, maxJump);
    }
};