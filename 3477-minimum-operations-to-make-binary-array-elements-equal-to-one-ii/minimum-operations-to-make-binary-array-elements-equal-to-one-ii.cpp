class Solution {
public:
    int minOperations(vector<int>& nums) {
        int times = 0;
    
        for(auto num:nums){
            if((num==0&&times%2==0)||(num==1&&times%2==1)){
                times++;
            }
        }
        return times;

    }
};