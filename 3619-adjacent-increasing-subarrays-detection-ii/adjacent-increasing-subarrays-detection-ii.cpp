class Solution {
public:

    bool inc(vector<int>& nums,int mid){
        int n = nums.size();
        int k = mid;
        int cnt = 1;
        for(int i = 1;i<n-k;i++){
            if(nums[i-1]<nums[i]&&nums[i+k-1]<nums[i+k]){
                cnt++;
            }else{
                if(mid<=cnt) return true;
                cnt=1;
            }
        }
        if(cnt>=mid) return true;
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int answer = 1;
        int low = 1;
        int high = n;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(inc(nums,mid)){
                low= mid+1;
                answer = mid;
            }
            else{
                high = mid-1;
            }
        }
        return answer;

    }
};