class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> freq;
        for(auto ch:magazine){
            freq[ch]++;
        }
        for(auto ch:ransomNote){
            
            if(freq.count(ch)>0){
                freq[ch]--;
                if(freq[ch]==0){
                    freq.erase(ch);
                }
            }else{
                return false;
            }
        }
        return true;
    }
};