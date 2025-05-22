class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(),queries.end());
        int n = queries.size();
        priority_queue<int> available;
        priority_queue<int,vector<int>,greater<int>> used;
        int cur = 0;
        int applied = 0;
        for(int i = 0;i<nums.size();i++){
           
            while(cur<queries.size()&&i==queries[cur][0]){
                available.push(queries[cur][1]);
                cur++;
            }
            nums[i]-=used.size();
            while(nums[i]>0 &&!available.empty()&&available.top()>=i){
                used.push(available.top());
                available.pop();
                nums[i]--;
                applied++;
            }
            if(nums[i]>0) return -1;
            while(!used.empty()&&used.top()==i){
                used.pop();
            }
        }
        return n-applied;

    }
};