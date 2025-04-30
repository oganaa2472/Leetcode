class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*set<int> s;
        for(int i = 0;i<nums.size();i++){
            s.insert(nums[i]);
        }*/
        sort(nums.begin(),nums.end());
        int n = nums.size();
        n = n - k;
        int i = 1;
        return nums[n];
    }
};