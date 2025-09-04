class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> freq;
        for(auto& str:strs){
            vector<int> f(26,0);

            for(auto& ch:str){
                f[ch-'a']++;
            }
            string key = "";
            for (int count : f) {
                key += '#' + std::to_string(count); 
            }
            freq[key].emplace_back(str);
        } 
        vector<std::vector<std::string>> result;
        for (const auto& pair : freq) {
            result.emplace_back(pair.second);
        }
        
        return result;
        }
};