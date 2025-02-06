class Solution {
public:
    int n;
    vector<int> minDp,maxDp;
    vector<int> nums;
    int solve(int index){
        if (index == 0) {
            minDp[0] = maxDp[0] = nums[0];
            return nums[0];
        }
        if(maxDp[index]!=INT_MIN) return maxDp[index];

        int prev_max = solve(index - 1);
        int prev_min = minDp[index - 1];

        
        maxDp[index] = max({nums[index], nums[index] * prev_max, nums[index] * prev_min});
        minDp[index] = min({nums[index], nums[index] * prev_max, nums[index] * prev_min});

        return maxDp[index];
      
    }
    int maxProduct(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        maxDp.assign(n, INT_MIN); 
        minDp.assign(n, INT_MAX);

        int result = INT_MIN;

        for (int i = 0; i < n; i++) {
            result = max(result, solve(i));
        }
        return result;
       

    }
};