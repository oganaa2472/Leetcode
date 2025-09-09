// monotonic queue
// [8,7,6,9]
// decreasing order
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> answer;
            deque<int> dq;
            int left = 0,right=0;
            while(right<nums.size()){
                // pop smaller elements from the q 
                while(!dq.empty()&&nums[dq.back()]<nums[right]){
                    dq.pop_back();
                }
                dq.push_back(right);
                // out of bound remove left most position
                if(left>dq.front()){
                    dq.pop_front();
                }
                if(right+1>=k){
                    answer.push_back(nums[dq.front()]);
                    left++;
                }
                right++;
            }
            return answer;
        }
};