class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
     
        vector<int> prefix(n + 1, 0);
       
        for(auto q:queries){
            int left = q[0];
            int right = q[1];
            prefix[left]--;
            prefix[right+1]++;
        }
     
        for (int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1];
        }

       
       for(int i = 0;i<n;i++){
        if(prefix[i]+nums[i]>0) return false;
        }

        
        return true;
    }
};