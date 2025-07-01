class Solution {
public:
    int possibleStringCount(string word) {
        unordered_map<char,int> mp;
        int ans = 1;
        int n = word.size();
        stack<int> st;
        int cnt = 0;
        for(int i = 0 ;i<n;i++){
            if(st.empty()){
                st.push(word[i]);
            }else if(st.top()==word[i]){
                cnt++;
            }else{
                st.push(word[i]);
                ans = ans+cnt;
                cnt=0;
            }
        }
        ans = ans + cnt;

        return ans;
    }
};