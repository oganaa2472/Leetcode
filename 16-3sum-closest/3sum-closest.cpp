class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int answer=10000;
        int ans = 10000;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-2;i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum<target){
                    if(answer>abs(sum-target)||ans==10000){
                        answer = abs(sum-target);
                        ans = sum;
                    }
                    left++;
                }else{
                     if(answer>abs(sum-target)||ans==10000){
                        answer = abs(sum-target);
                        ans = sum;
                    }
                    right--;
                }
            }
        }
        return ans;
    }
};