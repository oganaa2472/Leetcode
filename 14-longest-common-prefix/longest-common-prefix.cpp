class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        int mx = 0;
        for(int i = 0;i<strs.size();i++){
            int sz = strs[i].size();
            mx = max(mx,sz);
        }
        for(int i = 0 ;i<mx;i++){
            char ch = strs[0][i];
           for(int j = 0;j<n;j++){
            if(ch!=strs[j][i]){
                return ans;
            }
           }
           ans = ans+ch;
        }
        return ans;
    }
};