class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> p;
        for(auto& [x,y]:mp){
           p.push_back({y,x});
        }
        vector<int> answer;
        sort(p.begin(),p.end());
        for(int i = p.size()-1;i>=0&&k>0;i--){
            // cout<<p[i].second;
            answer.push_back(p[i].second);

            k--;
        }
        return answer;
       
    }
};