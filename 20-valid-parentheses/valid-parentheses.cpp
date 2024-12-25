class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                char ch = st.top();
                char cur;
                if(s[i]==')') cur = '(';
                else if(s[i]==']') cur='[';
                else cur = '{';
                if(ch!=cur) return false;
                st.pop();
            }
        }
        if(st.size()>0) return false;
        return true;
    }
};