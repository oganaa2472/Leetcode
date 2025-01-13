class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;

        for(int i = 0;i<s.size();i++){
            mp[s[i]]++;
        }
        int ans=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second>=3){
                
                if(it->second%2==0) ans=ans+2;
                else ans++;
            }else{
                ans = ans+it->second;
            }
        }
        return ans;
    }
};