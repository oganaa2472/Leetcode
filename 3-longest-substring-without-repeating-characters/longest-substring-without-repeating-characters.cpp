class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ch;

        int answer = 0;
        int n = s.size();
        int j = 0;
        int i = 0;
        while(i<n){
            while(ch.find(s[j])==ch.end()&&j<n){
                ch.insert(s[j]);
                j++;
            }
            answer = max((int)ch.size(),answer);
            ch.erase(s[i]);
            i++;
        }
        return answer;
    }
};