class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0];
        int ans = 0;
        int n = prices.size();
        for(int i = 1;i<n;i++){
            minBuy = min(prices[i],minBuy);

            ans = max({ans,0,prices[i]-minBuy});
        }
        return ans;
    }
};