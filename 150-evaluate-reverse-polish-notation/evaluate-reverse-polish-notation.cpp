class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(int i = 0;i<n;i++){
            if(tokens[i]=="+"||tokens[i]=="-"
            ||tokens[i]=="*"||tokens[i]=="/"){
                int first = (st.top());
                st.pop();
                int second = (st.top());
                st.pop();
                int ans ;
                if(tokens[i]=="+"){
                    ans =second+first;
                }else if(tokens[i]=="-"){
                    ans =second-first;
                }else if(tokens[i]=="*"){
                    ans =second*first;
                }else{
                    ans =second/first;
                }
                st.push(ans);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};