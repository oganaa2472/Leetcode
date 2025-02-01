class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(nums.size(),0);
        for(int i = 0;i<n;i++){
            if(nums[i]%2==1) p[i]=1;
            else p[i]=0;
        }
        if(n==1) return true;
        for(int i =1;i<n;i++){
            if(p[i]==p[i-1]) return false;
        }
        return true;
    }
};