class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int n = part.size();
        for(int i = 0;i<s.size();i++){
            st.push(s[i]);
            if(st.top()==part[n-1]&&st.size()>=n){
                int k = n-2;
                stack<char> tmp;
                st.pop();
                tmp.push(part[n-1]);
               
                while(k>=0&&st.top()==part[k]){
                    tmp.push(st.top());
                    st.pop();
                    k--;
                }
                // cout<<k<<"=";
                if(k!=-1){
                   while(!tmp.empty()){
                    st.push(tmp.top());
                    tmp.pop();
                   }
                }
            }
        }
        string answer;
        while(!st.empty()){
            answer+=st.top();
            st.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;

    }
};