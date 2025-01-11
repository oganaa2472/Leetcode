class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int> m;
        if(s.size()==k) return true;
        for(int i = 0;i<s.size();i++){
            m[s[i]]++;
        }
        int count = 0 ;
        int even = 0;
        int ceven = 0;
        for(auto [x,y] : m){
            if(y==1) count++;
            else if(y%2==1){
                count++;
                ceven += y-1;
            }
            else {
                even++;
                ceven += y; 
            }
        }
        if(count>k) return false;

        k = k - count;
        if(ceven<k) return false;
        return true;
    }
};