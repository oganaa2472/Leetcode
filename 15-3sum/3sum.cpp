class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        set<vector<int>> st;
        vector<vector<int>> answer;
        int n = nums.size();
     
        for(int i =0 ;i<n;i++){
            int j = i+1;
            int k = nums.size()-1;

            while(j<k){
                
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    answer.push_back(triplet);
                    while(nums[j]==triplet[1]&&j<k) j++;
                    while(nums[k]==nums[2]&&k>j) k--;
                    
                }else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }else{
                    j++;
                }
            }
            while (i + 1 < n && nums[i + 1] == nums[i]) 
                i++;
        }
        // for(auto& s:st){
        //     answer.push_back(s);
        // }
        return answer;
    }
};