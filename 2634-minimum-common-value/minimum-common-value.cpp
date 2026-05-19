class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        for(int i = 0;i<nums1.size();i++){
            int left  = 0;
            int right = nums2.size()-1;
            while(left<=right){
                int mid = left+ (right-left)/2;
                if(nums1[i]==nums2[mid]){
                    return nums2[mid];
                }else if(nums1[i]>nums2[mid]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};