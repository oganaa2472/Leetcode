class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";

        while(s.size()<k){
            string temp = "";
            for(int i = 0;i<s.size();i++){
                char ch = s[i];
                ch++;
                temp += ch;
            }
            
            s += temp;
        }
        cout<<s;
        return s[k-1];
    }
};