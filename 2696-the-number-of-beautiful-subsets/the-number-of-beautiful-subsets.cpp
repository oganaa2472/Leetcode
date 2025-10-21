class Solution {
public:
    int solve(int i, vector<int>& nums,int k,vector<int>& values){
        int n = nums.size();
        if(i==n){
            return values.size()>0?1:0;
        }

        int res = solve(i+1,nums,k,values);
        
        if(values.empty()){
            values.push_back(nums[i]);
            res+=solve(i+1,nums,k,values);
            values.pop_back();
        }else{
            int added = 0;
            for(auto val:values){
                if(abs(val-nums[i])==k){
                    added = 1;
                    break;
                }
            }
            if(added==0){
                values.push_back(nums[i]);
                res+=solve(i+1,nums,k,values);
                 values.pop_back();
            }
        }
        
        
        return res;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> empty;
        return solve(0,nums,k,empty);
    }
};