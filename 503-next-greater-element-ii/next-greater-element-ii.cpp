class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        vector<int> nextGreater(2*n,-1);
        stack<int> st;
        for(int i = 0;i<2*n;i++){
            while(!st.empty()&&nums[st.top()]<nums[i]){
                nextGreater[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        vector<int> answer(n,-1);
        for(int i = 0;i<n;i++){
            answer[i] = nextGreater[i];
        }
        return answer;

    }
};