class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> result(n,-1);
        unordered_map<int,int> mp;
        for(int i = 0;i<n*2;i++){
            while(!st.empty()&&nums[st.top()]<nums[i%nums.size()]){
                result[st.top()] = nums[i%nums.size()]; 
                st.pop();
            }
            st.push(i%nums.size());
        }
        
        return result;
    }
};