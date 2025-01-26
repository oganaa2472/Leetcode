class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       unordered_map<char,int> mp1;
       unordered_map<char,int> mp2;
       for(int i= 0;i<s1.size();i++){
        mp1[s1[i]]++;
       }
       int k = s1.size();
       int i = 0,j=s2.size();
       int r = 0;
        while (i<=j-k){
            while(r<k+i){
                mp2[s2[r++]]++;
            }
            if(mp2==mp1) return true;
            mp2[s2[i]]--;
            if(mp2[s2[i]]==0) mp2.erase(s2[i]);
            i++;
        }
        return false;
    }
};