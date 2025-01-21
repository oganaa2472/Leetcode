class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        // n - k + 1 = 4- 2+ 1 ; 
        int gcd = __gcd(n,k); // 
        long long ans= 0;
        vector<int> check[n+1];
        for (int i = 0; i < gcd; ++i) {
            vector<int> v;
            for(int j=i;j<arr.size();j+=gcd){
                v.push_back(arr[j]);
            }
            sort(v.begin(),v.end());
            int median = v[v.size()/2];
            for(int j = i;j<arr.size();j+=gcd){
                ans = ans+abs(median-arr[j]);
            }
        }
        return ans;
    }
};