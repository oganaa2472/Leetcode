class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> size;
        
        int n = nums.size();
        for(int i = 0;i<n;i++){
            size.insert(nums[i]);
        }
        int k = size.size();
        int left=0;
        int right =0;
        int ans= 0;
        int count = 0;
        unordered_map<int,int> mp;
        while(right<n){
            mp[nums[right]]++;
          
            while(mp.size()==k){
                ans+=n-right;
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                } 
                
                // st.erase(nums[left]);
                left++;
            }
           
            right ++ ;
        }
        return ans;
    }
};