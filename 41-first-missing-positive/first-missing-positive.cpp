class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      set<int> st(nums.begin(),nums.end());
      int i = 1;
      while(true){
        if(st.count(i)==0)
            return i;
        i++;
      }
      return -1;
    }
};