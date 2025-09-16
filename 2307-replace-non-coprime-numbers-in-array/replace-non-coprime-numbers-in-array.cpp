class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;

        for(int x:nums){
            st.push_back(x);
            while(st.size()>=2){
                int b = st.back(); st.pop_back();
                int a = st.back(); st.pop_back();
                int g = gcd(a, b);
                if (g == 1) {
                    st.push_back(a);
                    st.push_back(b);
                    break;
                }
                else {
                    long long l = 1LL * a / g * b; // LCM
                    st.push_back((int)l);
                }
            }
        }
        return st;
    }
};