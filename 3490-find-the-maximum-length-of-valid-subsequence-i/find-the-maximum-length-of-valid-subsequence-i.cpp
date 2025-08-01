class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int odd=0;
        int odd_count = nums[0]%2==1;
        int alternative = 1;
        bool expect = nums[0]%2!=0?true:false;

        for(int i = 1;i<n;i++){
            if((expect==true && nums[i]%2==0)||(expect==false && nums[i]%2==1)){
                alternative++;
                expect = !expect;
            }
            if(nums[i]%2==1) odd_count++;
        }
        return max({odd_count,n-odd_count,alternative});
    }

};