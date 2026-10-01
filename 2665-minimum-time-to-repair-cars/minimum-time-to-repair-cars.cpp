class Solution {
public:
    long long check(vector<int>& ranks,int cars,long long mid){
        long long cnt = 0;
        int n = ranks.size();
        for(int i = 0;i<n;i++){
            long long cal = sqrt(mid/ranks[i]);
            cnt+= cal;
        }
        return cnt>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = LLONG_MAX;


        long long ans = high;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(check(ranks,cars,mid)){
                ans = mid;
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};