class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m,mp;

        for(int i = 0;i<=n-k;i++){
            mp.clear();
            for(int j = i;j<k+i;j++){
                // cout<<nums[j]<<" ";
                mp[nums[j]]++;
            }
            for(auto [x,y]:mp){
                m[x]++;
            }
            // cout<<endl;
        }
      
        int ans = -1;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second==1) {
                ans = max(ans,it->first);
            }
        }
        return ans;
    }
};