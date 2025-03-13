class Solution {
public:
    vector<int> bloomDay;
    bool bs(int mid,int m,int k){
        int n = bloomDay.size();
        int count = 0;
        int numberOfCount = 0;
        for(int i = 0;i<n;i++){
            if(mid>=bloomDay[i]){
                count++;
            }else{
                count = 0;
            }

            if(count == k) {
                numberOfCount++;
                count = 0 ;
            }
        }
        return numberOfCount>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int right = *max_element(bloomDay.begin(),bloomDay.end());
        this->bloomDay = bloomDay;
        int ans = -1;
        int left = 1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(bs(mid,m,k)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};