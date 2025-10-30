class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,vector<int>> mp;
        map<char,int> m1,m2;
        int n = s.size();
        for(int i = 0;i<n;i++){
            mp[s[i]].push_back(i);
            m1[s[i]]++;
            m2[t[i]]++;
        }
        if(m1.size()!=m2.size()) return false;
        vector<bool> visit(n,false);

        for(int i = 0;i<n;i++){
            // if(visit[i]==false){
            //     visit[i] = true;
                char chart = t[i];
                char chars = s[i];
                vector<int> val= mp[chars];
                for(int index:val){
                    // visit[index] = true;
                    if(chart!=t[index]){
                        return false;
                    }
                }
            // }
            
        }
        return true;
    }
};