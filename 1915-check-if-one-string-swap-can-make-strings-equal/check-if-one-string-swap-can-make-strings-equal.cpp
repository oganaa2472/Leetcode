class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char,int> m1,m2;
        int cnt = 0;
        int n = s1.size();
        for(int i = 0;i<n;i++){
            m1[s1[i]]++;
            m2[s2[i]]++;
            if(s1[i]!=s2[i]) cnt++;
        }
        if(m1!=m2|| cnt>2) return false;
        return true;

    }
};