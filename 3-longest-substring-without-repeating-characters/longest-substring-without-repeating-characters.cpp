class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j = 0;
        int n = s.size();
        unordered_map<char,int> mp;
        int ans = 0;
        for(int i = 0;i<n;i++){
            while(mp.count(s[j])==0&&j<n){
                mp[s[j]]++;
                j++;
            }
            ans = max(ans,j-i);
            mp[s[i]]--;
            if(mp[s[i]]==0) mp.erase(s[i]);
        }
        return ans;
    }
};