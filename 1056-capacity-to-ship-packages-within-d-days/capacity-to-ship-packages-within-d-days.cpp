class Solution {
public:
    vector<int> w;
    int days;
    int check(int current){
        int needed =1;
        int c = 0;
        for(int i = 0;i<w.size();i++){
            c=c+w[i];
            if(c>current){
                needed++;
                c = w[i];
            }
        }
        return needed<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(),weights.end());
        int right = accumulate(weights.begin(),weights.end(),0);
        this->days = days;
        this->w = weights;
        while(left<right){
            int mid = left + (right-left)/2;
            if(check(mid)){
                right = mid;
            }else {
                left = mid+1;
            }
        }
        return left;
    }
};