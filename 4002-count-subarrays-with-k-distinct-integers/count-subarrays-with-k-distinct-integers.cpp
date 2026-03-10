
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        long long ans = 0;
        int n = nums.size();
        int j1=-1,j2=-1,cnt = 0;
        map<long long,long long> f1,f2;
        for(int i = 0;i<n;i++){
            while(j1<n&&f1.size()<k+1){
                j1++;
                if(j1<n){
                    f1[nums[j1]]++;
                }
            }
            while(j2<n&&cnt<k){
                j2++;
                if(j2<n){
                    f2[nums[j2]]++;
                    if(f2[nums[j2]]==m) cnt++;
                }
            }
            if(j1>j2){
                ans+=j1-j2;
            }
            f1[nums[i]]--;
            if(!f1[nums[i]]) f1.erase(nums[i]);
            f2[nums[i]]--;
            if(f2[nums[i]]==m-1) cnt--;
        }
        return ans;
    }
};