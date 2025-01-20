class Solution {
public:
   typedef long long ll;
   int mod = 1e9+7;
   vector<ll> fact,factInverse;
   Solution(){
    fact.resize(1e5);
    factInverse.resize(1e5);
    fact[0] = 1;
    for(int i = 1; i < 100000; i++){fact[i] = fact[i-1] * i % mod;}
    factInverse[100000 - 1] = binpow(fact[100000 - 1], mod - 2);
    for(int i = 100000 - 2; i >= 0; i--){factInverse[i] = factInverse[i+1] * (i+1) % mod;}
   }
    
    ll binpow(ll a, ll b){
        ll res = 1;
        while (b) {
            if (b % 2) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b /= 2;
        }
        return res;
    }
    ll comb(ll n, ll r) {
        if (r > n || r < 0) return 0;
        return fact[n] * factInverse[r] % mod * factInverse[n - r] % mod;
    }
    int minMaxSums(vector<int>& nums, int k) {
       
        int n = nums.size();
        sort(nums.begin(), nums.end());

        ll cnt = 0;

        for(ll i = 0 ;i<n;i++){
            for(ll j = 1; j <= k; j++){
                if (i >= j - 1) {
                    ll mini = (nums[i] * comb(i, j - 1)) % mod;
                    cnt = (cnt + mini) % mod;
                }
            }
            for(ll j = 1; j <= k; j++){
                if(n - i - 1 >= j - 1){
                    ll maxi = (nums[i] * comb(n - i- 1, j - 1)) % mod;
                    cnt = (cnt + maxi) % mod;
                }
            }
        }
        return cnt%mod;
    }
};