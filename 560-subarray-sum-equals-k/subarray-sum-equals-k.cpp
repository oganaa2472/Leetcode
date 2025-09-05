class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> storeSum;
        storeSum[0] = 1;
        int result = 0;
        int sum = 0;
        for(auto num:nums){
            sum += num;
            if(storeSum.find(sum-k)!=storeSum.end()){
                result += storeSum[sum-k];
            }
            storeSum[sum]++;
        }
        return result;
    }
};