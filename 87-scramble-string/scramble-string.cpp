class Solution {
public:
    bool f(string a, string b, unordered_map<string, bool> &mp) {
    if(a==b) return 1;
        if(a.size() != b.size()) return 0;
        string key=a+'*'+b;
        if(mp.find(key) != mp.end()) return mp[key];
        int i, n=a.size();
        bool swap=0, notSwap=0;
        for(i=1;i<n;i++) {
            swap=f(a.substr(0, i), b.substr(n-i, i), mp) and 
                    f(a.substr(i, n-i), b.substr(0, n-i), mp);
            notSwap=f(a.substr(0, i), b.substr(0, i), mp) and 
                    f(a.substr(i, n-i), b.substr(i, n-i), mp);
            if(swap || notSwap) return mp[key] = 1;
        }
        return mp[key] = 0;
    }
    bool isScramble(string a, string b) {
        unordered_map<string, bool> mp;
        return f(a, b, mp);
    }
};