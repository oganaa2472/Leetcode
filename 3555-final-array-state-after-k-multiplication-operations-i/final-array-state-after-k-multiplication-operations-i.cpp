class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        for(int i = 0;i<k;i++){
            int min_value = INT_MAX;
            int index=-1;
            for(int j =0;j<n;j++){
                if(min_value>nums[j]){
                    min_value = nums[j];
                    index = j;
                }
            }
            nums[index]=nums[index]*multiplier;
            
        }
        return nums;
    }
};