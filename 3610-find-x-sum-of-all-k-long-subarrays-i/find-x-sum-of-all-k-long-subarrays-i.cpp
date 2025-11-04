class Solution {
public:
    static bool comparator(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;  // If frequencies are the same, sort by value in descending order
        }
        return a.first > b.first;  // Otherwise, sort by frequency in descending order
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> answer(n-k+1);
        int dif = n - k;
        for(int i = 0;i<=dif;i++){
            unordered_map<int,int> mp;
            for(int j = i;j<i+k;j++){
                mp[nums[j]]++;
            }
            vector<pair<int,int>> freq;
            for(auto& m:mp){
                freq.push_back({m.second,m.first});
            }
           sort(freq.begin(), freq.end(), comparator);
            int sum = 0;
            int t = 0;
            for(auto& f:freq){
                if(t>=x) break;
                sum +=f.first*f.second;
                t++;
            }
            answer[i] = sum;
          
        }
        return answer;
    }
};