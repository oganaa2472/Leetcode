class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }
        int count = 0;
        int answer = 0;
        unordered_map<int,bool> check;
        for(auto& [x,y]:mp){
            int count = 0;
            if(check[x]==false){
                int t = x;
                while(mp.count(t)>0){
                    count++;
                    check[t] =true;
                    t++;
                }
                answer = max(answer,count);
            }
        }
        return answer;
    }
};