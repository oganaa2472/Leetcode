class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int mx = 0;
        int zero=0;
        int one=0;
        for(int i = 0;i<n-1;i++){
            one = 0;
            if(s[i]=='0') zero++;
            for(int j = i+1;j<n;j++){
                if(s[j]=='1'){
                    one++;
                }
            }
            mx = max(mx,zero+one);
        }
        return mx;
    }
};