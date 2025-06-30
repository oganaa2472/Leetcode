class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int answer = 0;
        int n = prices.size();
        for(int i = 1;i<n;i++){
            int sell = prices[i];
            if(sell>buy){
                answer = max(answer,sell-buy);
            }
            buy = min(buy,sell);
        }
        return answer;
    }
};