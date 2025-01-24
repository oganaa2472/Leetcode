class Solution {
public:

    int solve(int index,vector<int>&stoneValue,vector<int>& dp){
        if(index>=stoneValue.size()) return 0;
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans = INT_MIN;

        ans = max(ans,stoneValue[index]-solve(index+1,stoneValue,dp));
        if(index+1<stoneValue.size()){
            ans=max(ans,stoneValue[index]+stoneValue[index+1]-solve(index+2,stoneValue,dp));
        }
        if(index+2<stoneValue.size()){
            ans=max(ans,stoneValue[index]+stoneValue[index+1]+stoneValue[index+2]-solve(index+3,stoneValue,dp));
        }
        return dp[index] = ans;
          
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1,-1);

        int answer = solve(0,stoneValue,dp);

        cout<<answer;
        if(answer>0) 
            return "Alice";
        else if(answer<0){
            return "Bob";
        }else
            return "Tie";
    
    }
};