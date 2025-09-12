class Solution {
public:
    int minSteps(string s, string t) {
     
        vector<int> ch1(27,0);
        vector<int> ch2(27,0);
        int n = s.size();
        int m=t.size();
        for(char ch:s){
            ch1[ch-'a'] ++;
        }
        for(char ch:t){
            ch2[ch-'a'] ++;
        }
        int ans = 0;
        for(int i = 0;i<26;i++){
                ans +=min(ch1[i],ch2[i]); 
            
        }
        return n+m-ans*2;
    }
};