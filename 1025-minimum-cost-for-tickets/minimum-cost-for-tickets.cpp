class Solution {
public:
    int dp[366];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size(),j=0,k=0;
        for(int i=0;i<n;i++)
        {
            while(days[i]-days[j]>=7)j++;
            while(days[i]-days[k]>=30)k++;
            dp[i+1]=min(dp[i]+costs[0],min(dp[j]+costs[1],dp[k]+costs[2]));
        }
        return dp[n];
    }
};