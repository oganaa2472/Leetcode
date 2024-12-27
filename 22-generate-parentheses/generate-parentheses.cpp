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
    void solve(int n, int left,int right,vector<string>& answer,string s){
        int l =  count(s.begin(), s.end(), '(');
        int r =  count(s.begin(), s.end(), ')');
        cout<<left<<" "<<right<<"s="<<s<<endl;
        if(left==0&&right==0){
            if(isValid(s)){
                answer.push_back(s);
            }
            return;
        }
        if(left<0||right<0||r>n||l>n) return ;
       
        if(left>0) solve(n,left-1,right,answer,s+"(");
        if (right>0) solve(n,left,right-1,answer,s+")");
    }
    vector<string> generateParenthesis(int n) {
        int left = n;
        int right = n;
        vector<string> ans;
        solve(n,left-1,right,ans,"(");
        return ans;
    }
};

