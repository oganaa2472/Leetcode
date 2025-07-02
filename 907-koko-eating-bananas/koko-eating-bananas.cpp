class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int res = r;
        while(l<=r){
            int k = (l+r)/2;
            long long total = 0;
            for(auto p:piles){
                total+= ceil(static_cast<double>(p)/k);
            }
            if(total<=h){
                res = k;
                r = k-1;
            }else{
                l = k+1;
            }
        }
        return res;
    }
};