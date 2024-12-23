class Solution {
public:
    string isAnagram(string s) {
       sort(s.begin(),s.end());
       return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
        unordered_map<string,vector<string>> mp;
        for(auto st : strs){
            mp[isAnagram(st)].push_back(st);
        }
        vector<vector<string>> ans;
        for(auto& [x,y]:mp){
            ans.push_back(y);
        }
        return ans;
    }
};