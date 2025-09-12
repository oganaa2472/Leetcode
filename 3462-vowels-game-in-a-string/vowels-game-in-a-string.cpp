class Solution {
public:
    bool doesAliceWin(string s) {
        int countvowels = 0;
        int other = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u')
                countvowels++;
            else{
                other++;
            }
        }
        if(countvowels==0)
            return false;
        else
            return true;
        
    }
};