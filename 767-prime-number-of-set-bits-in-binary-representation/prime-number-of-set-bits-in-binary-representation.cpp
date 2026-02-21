class Solution {
public:
    int countBits(int n){
        unsigned int c=0;
         unsigned int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    
public:
    int countPrimeSetBits(int left, int right) {
        int arr[] = {2,3,5,7,11,13,17,19};
        int ans = 0;
        while(left<=right){
            
            int count = countBits(left);
            cout<<count<<endl;
            for(int i = 0;i<=7;i++){
                if(arr[i]==count) ans++;
            }
            left++;
        }
        return ans;
    }
};