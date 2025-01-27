class Solution {
public:
    // bool ischeck(string s){
    //     stack<char> ch;
    //     for(int i = 0;i<s.size();i++){
    //         if(s[i]=='(') ch.push(s[i]);
    //         else{
    //             if(ch.empty()) return false;
    //             ch.pop();
    //         }
    //     }
    //     return ch.size()==0;
    // }
    void solve(string op,int open, int close,vector<string>& answer){
         if(open==0&&close==0){
            answer.push_back(op);
            return;
        }
        if(open==close){
            string str = op;
            str +="(";
            solve(str,open-1,close,answer);
        }
        else if(open == 0){
            string str = op;
            str+=")";
            solve(str, open, close-1, answer);
        }
        else if(close == 0){
            string str = op;
            str+="(";
            solve(str, open-1, close, answer);
        }else{
            string op1 = op;
            string op2 = op;
            op1.push_back('(');
            op2.push_back(')');
            solve(op1, open-1, close, answer);
            solve(op2, open, close-1, answer);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer;

        int open = n;
        int close = n;
       
        string op = "";
        solve(op, open, close, answer);
        return answer;
    }
};