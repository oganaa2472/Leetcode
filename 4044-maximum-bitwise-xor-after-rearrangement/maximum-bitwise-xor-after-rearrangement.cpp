class Solution {
public:
    string maximumXor(string s, string t) {
        int cntone = 0;
        int cntzero = 0;
        for(auto ch:t){
            if(ch=='1') cntone++;
            else cntzero++;
        }
        string result = "";
        for(auto ch:s){
            if(ch=='1'){
                if(cntzero>0){ 
                    result+='0',cntzero--;
                }
                else {
                    result+='1';
                    cntone--;
                }
            }else{
                if(cntone>0){ 
                    result+='1',cntone--;
                }
                else {
                    result+='0';
                    cntzero--;
                }
            }
        }
        int n = s.size();
        string res = "";
        for(int i = 0;i<n;i++){
            res+=(result[i]-'0')^(s[i]-'0')+'0';
        }
        return res;
    }

};