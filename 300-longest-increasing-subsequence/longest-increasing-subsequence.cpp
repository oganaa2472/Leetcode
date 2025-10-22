class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cur;
        // let's think about binary search solution 
        // 10 9
        int n = nums.size();
        for(int i = 0;i<n;i++){
            auto it = lower_bound(cur.begin(),cur.end(),nums[i]);
            if(it==cur.end()){
                cur.push_back(nums[i]);
            }else{
                *it = nums[i];
            }
        }
        return (int)cur.size();
    }
};