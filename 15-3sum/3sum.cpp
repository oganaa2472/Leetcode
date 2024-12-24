class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n=nums.size();
        for(int i = 0;i<n;i++){
            int k = n-1;
            int j = i+1;
       
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    st.insert({nums[i],nums[j],nums[k]});
                    k--;
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }else{
                    j++;
                }
            }

        }

        for(auto& s:st){
            ans.push_back(s);
        }
        return ans;
    }
};