class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]==0){
                nums[two++] = 2;
                nums[one++] = 1;
                nums[zero++] =  0;
            }else if(nums[i]==1){
                
                nums[two++] = 2;
                nums[one++] = 1;
            }else{
                nums[two++] = 2;
            }
        }
    }
};