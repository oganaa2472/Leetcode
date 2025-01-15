class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
        set<int> st;
        
       for(auto& num:nums){
        st.insert(num);
       }
        int ans = 0;
        int count = 1;
        for(auto& s:st){
            
            if(st.count(s+1)){
                count++;
            }else{
                count=1;
            }
            ans = max(ans,count);
        }

       return ans;
    }
};