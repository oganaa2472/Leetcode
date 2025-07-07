class Solution {
public:
   
        int getMaximumConsecutive(vector<int>& coins) {
	sort(begin(coins), end(coins));
	int curSum = 0;
	for(auto& coin : coins)
		if(coin <= curSum + 1) curSum += coin;
		else break;

	return curSum + 1;
}
    
};