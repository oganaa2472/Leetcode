class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> arrays(3);
        int n = nums.size();
        for(int i = 0 ;i<n;i++){
            arrays[nums[i]]++;
        }
        int k = 0;
        for(int i = 0;i<3;i++){
            while(arrays[i]>0){
                nums[k] = i;
                arrays[i]--;
                k++;
            }
        }
        
    }
};