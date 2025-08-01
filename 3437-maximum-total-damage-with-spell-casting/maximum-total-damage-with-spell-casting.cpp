class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<long long,long long> freq;
        map<int,long long> dp;
        for(auto p:power) freq[p]++;
        long long n=power.size(),ans = 0,prevEl,backEl=0;
        for(auto [el,fr]:freq){
            auto backit = freq.lower_bound(el-2);
            if(backit!=freq.begin()) backEl = (*(--backit)).first;
            dp[el] = max(dp[prevEl],el*fr+dp[backEl]);
            ans = max(ans,dp[el]);
            prevEl = el;
        }
        return ans;
    }
};