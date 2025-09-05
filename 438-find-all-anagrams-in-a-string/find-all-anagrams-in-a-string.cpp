class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> result;
            if(s.size() < p.size()) return result;
            vector<int> count(26,0);
            for(auto c:p){
                count[c-'a']++;
            }
            int left = 0, right = 0, difference = p.size();
            while(right<s.size()){
                if(count[s[right]-'a']>=1){
                    difference--;
                }
                count[s[right]-'a']--;
                right++;
                if(difference==0){
                    result.push_back(left);
                }
                if(right-left==p.size()){
                    
                    if(count[s[left]-'a']>=0){
                        difference++;
                    }
                    count[s[left]-'a']++;
                    left++;
                }
            }
            return result;
        }
    };