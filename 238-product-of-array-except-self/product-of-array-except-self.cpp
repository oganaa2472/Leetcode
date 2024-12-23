class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,0);
        int s= 1;
        int count = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==0){
                count++;
                if(count>=2) return answer;
            }else{
                s=s*nums[i];
            }
        }
        if(count==0){
            for(int i = 0;i<n;i++){
                answer[i] = s/nums[i];
            }
            return answer;
        }else{
            for(int i = 0;i<n;i++){
                if(nums[i]==0){
                    answer[i] = s;
                }
            }
            return answer;
        }
    }
};