class Solution {
public: 
    int check(int mid,vector<int>&w,int days){
        int day = 1;
        int sum = 0;
        for(int i = 0;i<w.size();i++){
            sum=sum+w[i];
            if(sum>mid){
                day++;
                sum = w[i];
            }
        }
        return day<=days;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int total = accumulate(w.begin(),w.end(),0);
        int left = *max_element(w.begin(), w.end());
        // int left = 0;
        int right = total;
        int ans = total;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(check(mid,w,days)){
                right = mid-1;
                ans = min(mid,ans);
            }else{
                left = mid+1;
            }
        }   
        return left;
    }
};