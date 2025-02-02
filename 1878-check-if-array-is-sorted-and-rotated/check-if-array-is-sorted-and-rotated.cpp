class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> num = nums;
        sort(num.begin(),num.end());
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            vector<int> arr = nums;
            for(int i = 0;i<nums.size();i++){
                nums[i] = arr[(i+1)%n];
            }
            if(nums==num) return true;
        }
        return false;
    }
};