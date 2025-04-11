class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        map<int,vector<int>> mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]%space].push_back(nums[i]);
        }
        
        int count = 0;
        
        for(auto [x,y]: mp){
        
            sort(y.begin(),y.end());
            if(y.size()>=count){
                count = y.size();        
            }
        }
        int div = -1;
         for(auto [x,y]: mp){
            sort(y.begin(),y.end());
            if(y.size()==count){
                if(div==-1) div = y[0];
                else div = min(div,y[0]);           
            }
        }
        return div;
    }
};