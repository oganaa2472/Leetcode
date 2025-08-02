class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&freq,int i,int j,int k ){
        if(i==j) return 0;
        if(freq[j]-freq[i]<=k) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]= min(freq[i]+solve(freq,i+1,j,k),freq[j]-(freq[i]+k)+solve(freq,i,j-1,k));
    }
    int minimumDeletions(string word, int k) {
        dp.resize(26,vector<int>(26,-1));
        vector<int>freq(26,0);
        for(int i=0; i<word.size(); i++){
            freq[word[i]-'a']++;
        }

        sort(freq.begin(),freq.end());
        return solve(freq,0,25,k);
    }
};