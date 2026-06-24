class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        vector<int> nextGreater(n,-1);
        for(int i = 0;i<n;i++){
            int cur = nums2[i];
            while(!st.empty()&&nums2[st.top()]<cur){
                nextGreater[st.top()] = cur;
                st.pop();
            }
            st.push(i);
        }
        // for(int i = 0;i<n;i++){
        //     cout<<nextGreater[i]<<" ";
        // }
        int m = nums1.size();
        vector<int> answer(m,-1);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    answer[i] = nextGreater[j];
                    break;
                }
            }
        }
        return answer;
    }
};