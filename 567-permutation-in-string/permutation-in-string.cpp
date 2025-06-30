class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> m;
        map<char, int> freq;
        int k = s1.size();
        
        for (char c : s1) m[c]++;
        
        int l = 0, n = s2.size();
        for (int r = 0; r < n; r++) {
            freq[s2[r]]++;
            if (r - l + 1 > k) {
                freq[s2[l]]--;
                if (freq[s2[l]] == 0)
                    freq.erase(s2[l]);
                l++;
            }
            if (freq == m)
                return true;
        }
        
        return false;
    }
};
