class Solution {
public:
    bool isCheck(int right,int left,int k,int sum){
        return right+1-left-sum<=k;
    }
    int longestSubarray(vector<int>& nums) {
        int answer = 0;
        for(int i = 1;i<2;i++){
            int sum = 0;
            int start = 0;
            
            for(int end = 0;end<nums.size();end++){
                if(nums[end]==1){
                    sum++;
                }
                while(!isCheck(end,start,1,sum)){
                    if(nums[start]==i) sum--;
                    start++;
                }
                answer = max(end-start,answer);
            }
        }
        return answer;   
    }
};