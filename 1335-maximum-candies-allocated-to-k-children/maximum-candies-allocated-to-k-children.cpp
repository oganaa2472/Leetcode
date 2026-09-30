class Solution {
public:
    int check(vector<int>& candies,long long k,int mid){
        long long count = 0;
        for(int i = 0;i<candies.size();i++){
            count+=candies[i]/mid;
        }
        return k<=count;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1;
        int right = 1e9;
        int ans = 0;
        while(left<=right){
            int mid = left+(right-left)/2;
            if (check(candies, k, mid)) {
                ans = mid;
                left = mid + 1;   // Илүү олон чихэр өгч чадах эсэхийг шалгана
            } else {
                right = mid - 1;  // Хүрэлцэхгүй байгаа тул багасгана
            }
        }
        return ans;
    }
};