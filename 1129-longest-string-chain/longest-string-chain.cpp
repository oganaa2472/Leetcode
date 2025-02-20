class Solution {
public:
    bool checkString(string s1,string s2){
        int n = s1.size();
        int m = s2.size();
        if(abs(n-m)>=2) return false;
        
        int count = 0;
        int i = n-1;
        int j = m-1;
        while(i>=0&&j>=0&& s1[i]==s2[j]){
            i--;
            j--;
            count++;
        }
        i=0;
        j=0;
        while(s1[i]==s2[j]){
            i++;
            j++;
            count++;
        }
        return count>=min(n,m);
    }
    static bool compareSize(const string &a, const string &b) {
            return a.size() < b.size(); 
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compareSize);

        int n = words.size();
        vector<int> dp(n+1,1);
        int ans = 1 ;
        for(int i = 1;i<n;i++){
            for(int j=0;j<i;j++){
                if(words[i].size()>words[j].size()&&checkString(words[i],words[j])){
                    dp[i] = max(dp[i],dp[j]+1);
                    ans = max(dp[i],ans);
                }
            }
        }
        
        return ans;
    }
};