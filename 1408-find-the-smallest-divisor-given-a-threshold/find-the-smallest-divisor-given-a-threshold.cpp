class Solution {
public:
    vector<int> nums;
    int t;
    bool bs(int val){
        double ans = 0;
        for(auto& num:nums){
            ans = ans + ceil((double)num/val);
        }

        return ans<=t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        /*
            Given an array of integers nums and an integer threshold 
            we will choose a positive integer divisor, divide all the array
            by it, and sum the division's result . Find the smallest divisor such
            that the result mentianed above os less than or equal to threshold

        */

        int tot = *max_element(nums.begin(),nums.end());

        int left = 1; 
        int right = tot;
        this->nums = nums;
        t = threshold;
        int ans = tot;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(bs(mid)){
                ans = min(mid,ans);
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;


    }
};