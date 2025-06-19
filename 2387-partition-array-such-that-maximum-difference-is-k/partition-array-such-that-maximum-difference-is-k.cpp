class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cur = nums[0];
        int cnt = 1;
        for(int i = 1;i<n;i++){
            // cout<<nums[i]-cur<<" ";
            if(nums[i]-cur>k){
                cur = nums[i];
                cnt++;
            }
               
            
        }
        return cnt;
    }

};