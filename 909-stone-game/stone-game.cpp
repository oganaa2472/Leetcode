class Solution {
public:
    int solve(int index,vector<int>&piles,int k,vector<vector<int>>&dp){
        if(index>=piles.size()){
            return 0;
        }
        if(dp[index][k]!=-1){
            return dp[index][k];
        }
        if(k==1){
            int pick =piles[index]+solve(index+1,piles,0,dp);
            int skip = solve(index+1,piles,1,dp);
            return dp[index][k] = max(pick,skip);
        }else{
            int pick =piles[index]+solve(index+1,piles,1,dp);
            int skip = solve(index+1,piles,0,dp);
            return dp[index][k] = max(pick,skip);
        }
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n,vector<int>(3,-1));
        int sum = accumulate(piles.begin(),piles.end(),0);
        int answer = solve(0,piles,1,dp);
        cout<<answer<<" ";
        if(sum/2<answer) return true;
        else return false;

    }
};