class Solution {
public:
    static bool cmp(pair<int, int>& a, 
        pair<int, int>& b) 
    { 
        return a.second < b.second; 
    } 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;

        int n = nums.size();
        for(int i = 0;i<n;i++){
            m[nums[i]]++;
        }
        vector<pair<int, int> > a; 
 

        for (auto& it : m) { 
            a.push_back(it); 
        } 
         sort(a.begin(), a.end(), cmp); 
        vector<int> answer;
        for(int i = 0;i<k;i++){
            answer.push_back(a[a.size()-1-i].first);
        }
        return answer;
       
    }
};