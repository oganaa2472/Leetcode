class Solution {
public:
    bool isCheck(int right,int left,int k,int sum){
        return right+1-left-sum<=k;
    }
    int longestOnes(vector<int>& nums, int k) {
        int answer = 0;
        for(int i = 1;i<2;i++){
            int sum = 0;
            int start = 0;
            
            for(int end = 0;end<nums.size();end++){
                if(nums[end]==1){
                    sum++;
                }
                while(!isCheck(end,start,k,sum)){
                    if(nums[start]==i) sum--;
                    start++;
                }
                answer = max(end+1-start,answer);
            }
        }
        return answer;
    }
};