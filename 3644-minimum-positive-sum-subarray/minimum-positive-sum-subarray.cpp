class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX; 
        int curSum = 0;    
        int start = 0;         
        bool isCheck = false;
        for (int end=l; end<=r; ++end) {
            int curSum = 0;
           for(int i = 0;i<end;i++){
               curSum=curSum + nums[i];
           }
            if(curSum>0){
                minSum = min(curSum,minSum);
                isCheck = true;
            }
            for(int i = end;i<n;i++){
                curSum+=nums[i] - nums[i-end];
                 if(curSum>0){
                    minSum = min(curSum,minSum);
                    isCheck = true;
                }
            }
        }

        // If no valid subarray was found, return -1
        return isCheck == false ? -1 : minSum;
    }
};