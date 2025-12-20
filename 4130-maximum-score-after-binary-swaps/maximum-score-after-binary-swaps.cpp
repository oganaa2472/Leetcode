class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n = nums.size();
        priority_queue<long long> pq;
        long long i = 0,answer = 0;
        while(i<n){
            pq.push(nums[i]);
            if(s[i]=='1'){
                answer+=pq.top();
                pq.pop();
            }
            i++;
        }
        return answer;
    }
};