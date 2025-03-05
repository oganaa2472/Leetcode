class Solution {

    int dp[][];
    public int helper(int i,int x,int[] rewardValues,int n){

        if(i==n || x>=rewardValues[n-1]){
            return 0;
        }
        if(dp[i][x]!=0){
            return dp[i][x];
        }

        int ans = 0;
        if(x<rewardValues[i]){
            ans = Math.max(rewardValues[i]+helper(i+1,x+rewardValues[i],rewardValues,n),helper(i+1,x,rewardValues,n));
        }else{
            ans  =helper(i+1,x,rewardValues,n);
        }

        dp[i][x] = ans;
        return dp[i][x];
    }
    public int maxTotalReward(int[] rewardValues) {

        int n= rewardValues.length;
        Arrays.sort(rewardValues);

        dp = new int[n+1][rewardValues[n-1]];
        return helper(0,0,rewardValues,n);
    }
}