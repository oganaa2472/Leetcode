class Solution {
public:

    vector<int> bloomDay;
    bool check(int mid,int m,int k){
        int numOfType = 0;
        int count = 0;
        int n = bloomDay.size();
        for(int i = 0;i<n;i++){
            if(bloomDay[i]<=mid){
                count++;
            }else{
                count=0;
            }
            if(count==k) {
                numOfType++;
                count=0;
            }
        }
        
        return numOfType>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        // if(m*k>n) return -1;
      

        // sort(bloomDay.begin(),bloomDay.end())
        
        int right = *max_element(bloomDay.begin(),bloomDay.end());
        this->bloomDay=bloomDay;
        int left = 0;
    
        int ans = -1;

        while(left<=right){
            int mid = left+(right-left)/2;
            if(check(mid,m,k)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;

    }
};