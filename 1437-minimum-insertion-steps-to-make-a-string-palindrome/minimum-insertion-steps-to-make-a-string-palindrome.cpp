class Solution {
public:
    int lcs(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);


        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
          prev=curr;
        }

        return curr[m];
    }

    int minInsertions(string s) {
        int n = s.length();
        string sReverse = s;
        reverse(sReverse.begin(), sReverse.end());
        return n - lcs(s, sReverse);
    }
};