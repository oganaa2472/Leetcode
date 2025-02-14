class Solution {
public:
    int search(vector<int>& nums, int target) {

        if(nums.size()==1){
            return target==nums[0]?0:-1;
        }
        auto it = max_element(nums.begin(),nums.end());

        
    
        int left = distance(nums.begin(), it);

        if(nums[0]<=target&&nums[left]>=target){
            cout<<"check-1"<<left;
            int low = 0;
            int high = left;
            while(low<=high){
                int mid = low+(high-low)/2;
                if(nums[mid]==target){
                    return mid;
                }else if(nums[mid]>target){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            return -1;
        }else{
            cout<<"check-2"<<left;
            int low = left+1;
            int high = nums.size()-1;
            while(low<=high){
                int mid = low+(high-low)/2;
                if(nums[mid]==target){
                    return mid;
                }else if(nums[mid]>target){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            return -1;
        }
    }
};