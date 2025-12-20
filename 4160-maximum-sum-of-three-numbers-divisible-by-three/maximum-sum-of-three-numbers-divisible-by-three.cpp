class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> freq;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            freq[nums[i]%3].push_back(nums[i]);
        }
        for (auto& [key, val] : freq) {
            sort(val.begin(), val.end());
        }
        int answer = 0;
        if(freq[0].size()>=3){
            int m = freq[0].size();
            answer = freq[0][m-1]+freq[0][m-3]+freq[0][m-2];
        } 
        if(freq[1].size()>=3){
            int m = freq[1].size();
            int group1 = freq[1][m-1]+freq[1][m-3]+freq[1][m-2];
            answer = max(group1,answer);
        }
        if(freq[2].size()>=3){
            int m = freq[2].size();
            int group2 = freq[2][m-1]+freq[2][m-3]+freq[2][m-2];
            answer = max(group2,answer);
        }
        if(freq[0].size()>=1&&freq[1].size()>=1&&freq[2].size()>=1){
            int m = freq[0].size();
            int k = freq[1].size();
            int z = freq[2].size();
            int group2 = freq[0][m-1]+freq[1][k-1]+freq[2][z-1];
            answer = max(group2,answer);
        }
        return answer;
    }
};