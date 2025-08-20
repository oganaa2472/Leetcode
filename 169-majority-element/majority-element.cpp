class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        int n=nums.size();
        vector<int> bit(32,0);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<=31;j++){
                bit[j]+=(nums[i]>>j)&1;
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