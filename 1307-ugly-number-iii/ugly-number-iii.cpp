typedef long long ll;
class Solution {
public:
        bool isFeasible(ll num,ll n,ll a, ll b, ll c){

        ll ab = a * b / __gcd(a,b);
        ll bc = b * c / __gcd(b,c);
        ll ac = a * c / __gcd(a,c); 
        ll abc = ab*c/__gcd(ab,c);
       ll result = (num/a)+(num/b)+(num/c)-(num/ab)-(num/bc)-(num/ac)+(num/abc);
        return result>=n;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        int low = 1;
        ll high = 2000000000;
        while(low<high){
            ll mid = low + (high-low)/2;
            if(isFeasible(ll(mid),ll(n),ll(a),ll(b),ll(c))){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};