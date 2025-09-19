class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> ch(26,0);
        int n = s.size();
        int mx=0;
        for(int i = 0;i<n;i++){
           ch[s[i]-'a']++;
        }
        sort(ch.begin(),ch.end());
        // cout<<ch[25]<<endl;
        int j = 25;
        while(j>=1&&ch[j]==ch[j-1]){
            j--;
        }
        int c = ch[j];
        // cout<<c<<endl;
        string answer = "";
        vector<int> cur(26,0);
        for(int i = 0;i<n;i++){
           cur[s[i]-'a']++;
           if(c<=cur[s[i]-'a']) {
               answer+=s[i];
           }
        }
        return answer;
        
    }
};