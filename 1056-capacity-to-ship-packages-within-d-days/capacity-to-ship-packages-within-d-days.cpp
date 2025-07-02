class Solution {
public:
    int canWe(vector<int>& weights, int days,int mid){
        int day = 1;
        int total = 0;
        for(auto w:weights){
            total+=w;
            if(total>mid){
                day++;
                total=w;
            }
        }
        return days>=day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        int res = r;
        while(l<=r){
            int mid = (l+r)/2;
            if(canWe(weights,days,mid)){
                res = min(mid,res);
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return res;
    }
};