class Solution {
public:
    bool isBalance(vector<int>& freq){
        int c= 0;
        for(int& f:freq){
            if(f==0) continue;
            if(c==0) c = f;
            else if(c!=f) return false;
        }
        return true;
    }
    int longestBalanced(string s) {
          int ans = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            vector<int> freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                if(isBalance(freq)){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
        
    }
};