class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int ans = 0;
        while(left<=right){
            long long mid = left+(right-left)/2;
            long long square= (mid * mid);
            if(square==x) return (int)mid;
            else if(square>x){
                right=mid-1;
            }else{
                ans = mid;
                left=mid+1;
            }
        }
        return ans;
    }
};