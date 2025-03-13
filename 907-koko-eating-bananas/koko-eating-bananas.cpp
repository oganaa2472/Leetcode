class Solution {
public:
    int h;
    vector<int> piles ;
    bool check(int mid){
        double sum = 0;
        for(int i = 0;i<piles.size();i++){
            // if(piles[i]>=mid)
                sum += ceil((double) piles[i] / mid);
        }
        return sum<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = *max_element(piles.begin(),piles.end());

        int left = 0;
        this->piles = piles;
        this->h = h;

        int ans = right;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(check(mid)){
                ans = min(mid,ans);
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};