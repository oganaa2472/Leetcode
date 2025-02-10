class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for(int i = 0;i<s.size();i++){
            if(isalpha(s[i])){
                st.push(s[i]);
            }else{
                if(!st.empty())
                    st.pop();
            }
        }
        string sk = "";
        while(!st.empty()){
            sk=sk+st.top();
            st.pop();
        }
        reverse(sk.begin(),sk.end());
        return sk;
    }
};