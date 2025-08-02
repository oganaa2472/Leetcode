class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
          bitset<100001> dp,validPrev,mask;
        dp[0] = 1;
        int maskId = 0;
        sort(rewardValues.begin(),rewardValues.end());
        for(auto val:rewardValues){
             while(maskId<val) mask[maskId++] = 1;
             validPrev = dp&mask;
             dp|=(validPrev<<val);
        }
        int res=1e5;
        while(!dp[res]) --res;
        return res;
    }
};