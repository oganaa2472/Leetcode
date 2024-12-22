class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>=0)
                st.insert(nums[i]);
        }
        
        int i = st.size()>0?(*st.begin()==0?0:1):1;
        for(auto& j:st){
            cout<<j<<" ";
            if(i==j)
                i++;
            else return i;
        }
        return i;
    }
};