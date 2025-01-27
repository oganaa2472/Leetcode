class Solution {
public:
    bool ischeck(string s){
        stack<char> ch;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='(') ch.push(s[i]);
            else{
                if(ch.empty()) return false;
                ch.pop();
            }
        }
        return ch.size()==0;
    }
    void solve(int i,int n, vector<string>& answer,string s){
        if(i==n*2){
            // cout<<s<<endl;
            if(ischeck(s)){
                answer.push_back(s);
            }
            return;
        }
        solve(i+1,n,answer,s+")");
        solve(i+1,n,answer,s+"(");

    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer;

        solve(1,n,answer,"("); 
        return answer;
    }
};