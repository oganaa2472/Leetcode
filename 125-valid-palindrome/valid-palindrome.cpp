class Solution {
public:
    
    bool isPalindrome(string s) {
    //    int i = 0;
    //    int j = s.size()-1;

    //    while(i<j){
    //     char ch = tolower(s[i]);
    //     char c2 = tolower(s[j]);
        
    //     if((isalpha(ch)||isdigit(ch))&&(isalpha(c2)&&isdigit(ch))){
    //         if(ch==c2) {
    //             i++;
    //             j--;
    //         }else{
    //             return false;
    //         }
    //     }
    //     else if((!isalpha(ch)&&!isdigit(ch))){
    //         i++;
    //     }
    //     else if((!isalpha(c2)&&!isdigit(c2))) {
    //        j--;
    //     }else{
    //         i++;
    //     }
    //    }
    //    return true;
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