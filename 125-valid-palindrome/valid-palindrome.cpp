class Solution {
public:
    bool alpha(char c){
        return (c>='A'&&c<='Z') ||(c>='a'&&c<='z') ||(c>='0'&&c<='9') ;
    }
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;

        while(l<r){
            while(l<r&&!alpha(s[l])){
                l++;
            }
            while(r>l&&!alpha(s[r])){
                    r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }
        return true;
        
    }
};