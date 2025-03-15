class Solution {
public:

    bool check(int mid,vector<int>& nums,int k){
        int needed = 0;
        int choose = -1;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]<=mid&&choose==-1){
                choose = i;
                needed++;
            }
            else if(nums[i]<=mid&&i-choose>1){
                needed++;
                choose=i;
            }
        }
        return needed>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        // we have k 
        int right = *max_element(nums.begin(),nums.end());
        int left  = *min_element(nums.begin(),nums.end());

        while(left<=right){
            int mid = left+(right-left)/2;
            if(check(mid,nums,k)){
                right = mid - 1;
            }else{
                left = mid+1;
            }
        }
        return left;
    }

};