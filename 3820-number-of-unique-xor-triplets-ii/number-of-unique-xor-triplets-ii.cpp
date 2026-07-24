class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        vector<bool> visit(3002,false);
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                visit[nums[i]^nums[j]] = true;
            }
        }
        vector<int> newpos(3001,false);
        for(int i = 0;i<=3000;i++){
            for(int j = 0;j<nums.size();j++){
                if((i^nums[j])<=3000&&visit[i^nums[j]]){
                    newpos[i] = true;
                }
            }
        }
        return count(newpos.begin(),newpos.end(),true);
    }
};