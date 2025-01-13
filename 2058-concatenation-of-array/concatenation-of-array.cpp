class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> answer(nums.size()*2,0);
        int n=nums.size()*2;
        for(int i = 0;i<n;i++){
            answer[i] = nums[i%nums.size()];
        }
        return answer;
    }
};