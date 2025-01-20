class Solution {    
public:
    void findNGE(vector<int>& nums2, vector<int>& nge){
        stack<int> st;
        for(int i = nums2.size()-1; i >=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(!st.empty()) nge[i] = st.top();
            st.push(nums2[i]);
        }
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       vector<int> nge(nums2.size(),-1);
        findNGE(nums2,nge);

        unordered_map<int,int> mp;
        for(int i = 0 ; i< nums2.size();i++){
            mp[nums2[i]] = nge[i];
        }
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};