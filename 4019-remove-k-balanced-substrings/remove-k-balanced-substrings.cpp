class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<char,int>> st;
        for(auto& ch:s){
            if(!st.empty()&&st.back().first==ch){
                st.back().second++;
            }else{
                st.push_back({ch,1});
            }
            int n = st.size();

            if(n>=2 && st[n-2].first=='(' &&st[n-2].second >= k&&
            st[n-1].first==')'&& st[n-1].second==k
            ){
                 st[n-2].second -= k;
                 st.pop_back();
                 if(st.back().second==0){
                    st.pop_back();
                 }
            }
        }
        string result = "";
        for (auto& p : st) {
            result += string(p.second, p.first);
        }
        
        return result;
    }
};