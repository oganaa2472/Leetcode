class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> result(nums2.size(),-1);
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty()&&nums2[st.top()]<nums2[i]){
                result[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        unordered_map<int,int> mp;
        for(int i = 0 ; i< nums2.size();i++){
            mp[nums2[i]] = result[i];
        }
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;
        
    }
};