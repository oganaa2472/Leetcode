class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        unordered_map<char,int> window;
        int answer = 0;
        while(r<n){
            
            while(window.count(s[r])>0){

                window[s[l]]--;
                if(window[s[l]]==0){
                    window.erase(s[l]);
                }
                l++;
            }
            window[s[r]]++;
            r++;
            answer = max(r-l,answer);
        }
        return answer;
    }
};