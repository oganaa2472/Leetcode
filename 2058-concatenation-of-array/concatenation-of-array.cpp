class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(2*n,0);

        for(int i = 0;i<n;i++){
            answer[i] = nums[i];
            answer[i+n] = nums[i];
        }
        return answer;
    }
};