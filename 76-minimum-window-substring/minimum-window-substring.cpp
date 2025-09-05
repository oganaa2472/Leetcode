class Solution {
public:
    string minWindow(string s, string t) {
       
        map<char,int> freq,window;
        for(auto ch:t){
            freq[ch]++;
        }
        int need = freq.size();
        int have = 0;
        int left = 0;
        int ans = INT_MAX;
        pair<int,int> res = {-1,-1};
        for(int right = 0;right<s.size();right++){
            char ch = s[right];
            window[ch]++;
            if(freq.count(ch)&&freq[ch]==window[ch]){
                have++;
            }       
            while(have==need){
                if((right-left+1)<ans){
                    ans = right-left+1;
                    res = {left,right};
                }
                window[s[left]]--;
                if(freq.count(s[left])&&window[s[left]]<freq[s[left]]){
                    have--;
                }
                left++;
            }
        }
        return ans==INT_MAX?"":s.substr(res.first,ans);
    }
};