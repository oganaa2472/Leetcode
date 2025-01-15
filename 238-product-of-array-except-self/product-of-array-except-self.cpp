class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0;
        int sub = 1;
        int n = nums.size();
        int index = -1;
        for(int i = 0;i<n;i++){
            if(nums[i]==0) {
                zero++;
                index = i;
            }
                
            else{
                sub=sub*nums[i];
            }
        }
        vector<int> answer(n,0);
        if(zero>1) return answer;
        else if(zero==1){
        
            answer[index] = sub;
            
            return answer;
        }else{
            for(int i = 0;i<n;i++){
                answer[i] = sub/nums[i];
            }
            return answer;
        }
    }
};