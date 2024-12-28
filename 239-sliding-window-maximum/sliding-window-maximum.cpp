class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer(nums.size()-k+1,0);
        int j = 0;
        int n = nums.size();
        map<int,int> m;
        for(int i = 0;i<=n-k;i++){
           while(j<k+i) {
            m[nums[j]]++;
            j++;
           }
           answer[i] = m.rbegin()->first;
           m[nums[i]]--;
           if(m[nums[i]]==0) m.erase(nums[i]);
        }
        return answer;

    }
};