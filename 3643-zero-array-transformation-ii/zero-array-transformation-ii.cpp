class Solution {
public:
    vector<int> nums;
    vector<vector<int>> q;
    bool check(int right){
        int prefix = 0;
        int n = nums.size();
        vector<int> diff(n+1,0);
        for(int i = 0;i<right;i++){
            int start = q[i][0];
            int end = q[i][1];
            int val = q[i][2];
            diff[start]+=val;
            diff[end+1]-=val;
        }

        for(int i = 0;i<n;i++){
            prefix += diff[i];
            if(prefix<nums[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
       
        this->nums=nums;

        int left = 0;
        int right = queries.size();
        q = queries;
        if(!check(right)) return -1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(check(mid)){
                right = mid-1;
            }else {
                left = mid+1;
            }
        }
        return left;
    }
};