class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i = 0;
        vector<int> nums;
        int n = cardPoints.size();
        int start = n-k;
        while(start<n){
            nums.push_back(cardPoints[start]);
            start++;
        }
        while(i<k){
            nums.push_back(cardPoints[i]);
            i++;
        }
        // for(auto it:nums)
        // {
        //     cout<<it<<" ";
        // }
      
        int left = 0;
        int right = 0;
        int sum = 0;
        int ans = 0;
        n= nums.size();
        while(left<=n-k){
            while(right<k+left){
                sum+=nums[right];
                right++;
                ans = max(sum,ans);
            }

            sum-=nums[left];
            left++;
        }
        return ans;
    }
};