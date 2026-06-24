class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        vector<int> nextGreater(10001,-1);
        for(int i = 0;i<n;i++){
            int cur = nums2[i];
            while(!st.empty()&&st.top()<cur){
                nextGreater[st.top()] = cur;
                st.pop();
            }
            st.push(cur);
        }
        // for(int i = 0;i<n;i++){
        //     cout<<nextGreater[i]<<" ";
        // }
        int m = nums1.size();
        for(int i = 0;i<nums1.size();i++){
            nums1[i] = nextGreater[nums1[i]];
        }
        return nums1;
    }
};