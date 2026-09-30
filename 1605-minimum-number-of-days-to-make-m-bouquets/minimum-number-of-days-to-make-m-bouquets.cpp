class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
       
        int n = bloomDay.size();
        if ((long long)m * k > n) {
            return -1;
        }
        int low = 1;
        int high = 1e9;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            int cnt = 0;
            int bouquets = 0;
            for(int i = 0;i<n;i++){
                if (bloomDay[i] <= mid) {
                    cnt++;
                    if (cnt == k) {
                        bouquets++;
                        cnt = 0; // Шинэ баглаанд зориулж тэглэнэ
                    }
                } else {
                    cnt = 0; // Дараалал тасарсан тул тэглэнэ
                }
            }
            if(bouquets>=m){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};