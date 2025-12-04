class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0] = nums[0];
        int mnVal = prefix[0];
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1]+nums[i];
            mnVal = min(mnVal,prefix[i]);
        }
        
        return mnVal>0?1:abs(mnVal)+1;

    }
};