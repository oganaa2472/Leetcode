class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        unordered_map<char,int> freq,window;

        for(auto c:t) freq[c]++;

        int have = 0;
        int need = freq.size();
        int resLen = INT_MAX;
        int l = 0;
        int n = s.size();
        pair<int,int> res={-1,-1};
        for(int r = 0;r<n;r++){
            char c = s[r];
            window[c]++;
            if(freq.count(c) && window[c]==freq[c]){
                have++;
            }
            while(have==need){
                if((r-l+1)<resLen){
                    resLen = r-l+1;
                    res = {l,r};
                }
                window[s[l]]--;
                if(freq.count(s[l])&&window[s[l]]<freq[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return resLen==INT_MAX?"":s.substr(res.first,resLen);
    }
};