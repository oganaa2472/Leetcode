class Solution {
public:
    unordered_map<int,int> freq;
    vector<int>nums;
    int n;
    int solve(int i,int k){
       
        if(i==n) return 1;
       
        int result = solve(i+1,k);

        if(!freq[nums[i]-k] && !freq[nums[i] + k]){
            freq[nums[i]]++;
            result+=solve(i+1,k);
            freq[nums[i]]--;
        }
        return result;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        // dp.resize(nums.size(),vector<int>(1001,-1));
        sort(nums.begin(),nums.end());
        this->nums = nums;
        n = nums.size();
        /*
            You are given an array nums of positive integers and a positive k A Subset of nums is beautiful 
            if does not contain two integers with absolute difference equal to k
            return the number of non-empty beautiful subsets of the array nums 
        */

        return solve(0,k)-1;
    }
};