class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
    
        long long ans=0;
        vector<int> count(24);
        for(auto hour:hours){
            ans += count[(24 - hour % 24) % 24];
            count[hour%24]++;
        }
        return ans;
    }
};