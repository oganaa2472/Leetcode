class Solution {
public:
    int f2(char ch1,char ch2,string s){
        map<int,int> freq;
        int n = s.size();
        freq[0] = -1;
        int ans = 0;
        int pref = 0;
        for(int i=0;i<n;i++){
            if(s[i]==ch1)  pref++;
            else if(s[i]==ch2)pref--;
            else freq.clear();
            if(freq.find(pref)==freq.end()){
                freq[pref] = i;
            }
            ans = max(ans,i-freq[pref]);
        }
        return ans;
    }
    int f3(string s) {
    map<pair<int,int>, int> freq;
    int n = s.size();
    freq[{0, 0}] = -1;  // base case (before any character)

    int val1 = 0, val2 = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') val1++;
        else if (s[i] == 'b') val2++;
        else {  // for any other character
            val1--;
            val2--;
        }

        pair<int,int> key = {val1, val2};

        if (freq.find(key) == freq.end()) {
            freq[key] = i;  // store first occurrence
        } else {
            ans = max(ans, i - freq[key]);  // update longest distance
        }
    }
    return ans;
}

    int longestBalanced(string s) {
        // image only 2 character 
        // think about prefix 
        // if we aabbbaabaabaab
        // prefix sum use prefix what is the longest one


        int ans = max({1,f3(s), f2('a','b',s),f2('b','c',s),f2('a','c',s)});
        int cnt = 1;
        int n = s.size();
        for(int i = 1;i<n;i++){
            if(s[i]==s[i-1]) cnt++;
            else cnt=1;
            ans=max(ans,cnt);
        }
        return ans;
    }
};