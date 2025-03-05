class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&freq,int i,int j,int k ){

        if(i==j){
            return 0;
        }
        if(freq[j]-freq[i]<=k)return 0;
        if(dp[i][j]!=-1) return dp[i][j];
       
        return dp[i][j]= min(freq[i]+solve(freq,i+1,j,k),freq[j]-(freq[i]+k)+solve(freq,i,j-1,k));
    }
    int minimumDeletions(string word, int k) {
        /*
        we are given a string word and an integer k 
        we consider word to be k-special if freq(word(i)) - freq(word(j))<=k for all indices i and j
        in the string. Here freq(x) denotes the frequency of the character x in word, y and denotes absolute 
        value of y return minumum number of characters you need to delete make to k - special
        */
        dp.resize(26,vector<int>(26,-1));
        vector<int>freq(26,0);
        for(int i=0; i<word.size(); i++){
            freq[word[i]-'a']++;
        }

        sort(freq.begin(),freq.end());
        return solve(freq,0,25,k);
    }
};