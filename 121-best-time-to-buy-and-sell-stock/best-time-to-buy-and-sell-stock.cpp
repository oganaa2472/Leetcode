class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int choose = prices[0];
        int n = prices.size();
        int answer = 0;

        for(int i = 1;i<n;i++){
            choose = min(prices[i],choose);
            if(choose<prices[i]){
                answer = max(prices[i]-choose,answer);
            }
        }
        return answer;
    }
};