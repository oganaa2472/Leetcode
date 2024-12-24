class Solution {
public:
    bool isPalindrome(string s) {
        string res ;
        int n =s.size();
        for(int i =0;i<n;i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')){
                res+=tolower(s[i]);
            }
        }
        int j = res.size()-1;
        int i=0;
        while(i<j){
            if(res[i]!=res[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};