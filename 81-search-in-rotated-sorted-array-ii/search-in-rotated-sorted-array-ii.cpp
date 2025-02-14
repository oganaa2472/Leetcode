class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        
        set<int> st;
        for(int i = 0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        auto it = st.lower_bound(target);
        if(it!=st.end()){
            if(*it==target) return true;
            return false;
        }
        return false;
    }
};