class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        int n=s.length();
        vector<int>cnt(26,0);
        for(auto &it:s){
            cnt[it-'a']++;
        }
        stack<char>st;
        for(auto &it:s){
            if(st.empty() || st.top() <= it){st.push(it);}
            else{
                while(st.empty() == false && st.top() > it && cnt[st.top()-'a'] >= 2){
                    cnt[st.top()-'a']--;
                    st.pop();
                }
            st.push(it);
            }
        }
        string res="";
        while(st.empty() == false){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        n= res.length();

        while(n >= 1 && cnt[res[n-1]-'a'] > 1){
            cnt[res[n-1]-'a']--;
            res.pop_back();
            n=res.size();
        }
        return res;
    }
};