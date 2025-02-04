class Solution {
public:
    vector<string> splitString(const string& str, char delimiter) {
        vector<string> tokens;
        stringstream ss(str);
        string token;
        
        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        
        return tokens;
    }
    string simplifyPath(string path) {
        vector<string> result = splitString(path,'/');

        int n = result.size();
        stack<string> st;

        for(int i = 0;i<n;i++){
            if(result[i]==".."){
                if(!st.empty()){
                    st.pop();
                }
                continue;
            }
            else if(result[i]=="."||result[i].size()==0) continue;
            st.push(result[i]);   
        }
        
        vector<string> answer;
        while(!st.empty()){
            answer.push_back(st.top());
            st.pop();
        }
        string res = "/";
        int size = answer.size();
        for(int i = 0;i<answer.size();i++){
            res+=answer[size-1-i]+"/";
        }
        
        return res.size()>1?res.substr(0,res.size()-1):"/";
    }
};