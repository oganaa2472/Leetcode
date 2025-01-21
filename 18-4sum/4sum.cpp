class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                long long low = j+1;
                long long high = n-1;
                
                while(low<high){
                    if((long long)nums[i]+nums[j]+nums[low]+nums[high]==(long long)target){
                        vector<int> four = {
                            nums[i],nums[j],nums[low],nums[high]
                        };
                        answer.push_back(four);
                        while(nums[low]==four[2]&&low<high) low++;
                        while(nums[high]==four[3]&&high>low) high--;
                    }else if((long long)nums[i]+nums[j]+nums[low]+nums[high]>(long long)target){
                        high--;
                    }else{
                        low++;
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j]) 
                    j++;
            }
             while (i + 1 < n && nums[i + 1] == nums[i]) 
                i++;
        }
        return answer;
    }
};