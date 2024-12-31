class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
        int n=nums.size();

        vector<int> prefixSum(n,0); 
        vector<int> suffixSum(n,0);
        prefixSum[0] =  0;
        suffixSum[n-1] = 0;
        for(int i = 1;i<n;i++){
            if(nums[i-1]>=nums[i]){
                prefixSum[i] = prefixSum[i-1]+1;
            }else{
                prefixSum[i] = prefixSum[i-1];
            }
        }
        for(int i = n-2;i>=0;i--){
             if(nums[i+1]>=nums[i]){
                suffixSum[i] = suffixSum[i+1]+1;
            }else{
                suffixSum[i] = suffixSum[i+1];
            }
          
        }
        vector<int> answer;

        for(int i = time;i<n-time;i++){

            if(
            prefixSum[i]-time>=prefixSum[i-time]&&
            suffixSum[i]-time>=suffixSum[i+time]){
                answer.push_back(i);
            }
        }
        return answer;

        
    }
};