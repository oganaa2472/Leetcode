class Solution {
public:
    long long total(long long x, vector<int>&cost,vector<int>&nums){
       long long total = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            total += 1LL * abs(nums[i] - x) * cost[i];
        }
        return total;

    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long left = 1 ;
        long long right = (long long) *max_element(nums.begin(),nums.end());

    
        while(left<right){
            long long mid = left+(right-left)/2;
            if(total(mid,cost,nums)>total(mid+1,cost,nums)){
                left =  mid+1;
               
            }else{
                right = mid; 
            }
        }
        return total(left,cost,nums);
    }
};