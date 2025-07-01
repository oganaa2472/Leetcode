class Solution {
public:
    string solve(int& i,string& s){
        string res;
        int k = 0;
        while(i<s.size()){
            char c = s[i];
            if(isdigit(c)){
                k = k*10+(c-'0');
            }else if(c=='['){
                i++;
                string sub = solve(i,s);
                while(k--){
                    res+=sub;
                }
                k=0;
            }else if(c==']'){
                return res;
            }else{
                res+=c;
            }
            i++;
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return solve(i, s);
    }
};