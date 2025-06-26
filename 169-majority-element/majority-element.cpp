class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> bit(32,0);
        for(int num:nums){
            for(int i = 0;i<32;i++){
                bit[i]+=(num>>i)&1;
            }
        }
        int res = 0;
        for(int i = 0;i<32;i++){
            if(bit[i]>n/2){
                res|=(1<<i);
            }
        }
        return res;
    }
};