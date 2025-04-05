class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        int sum = 0;
        int x =0;
        int n = arr.size();
        for( int i = 0 ; i < ( 1 << n ) ; ++i ) {
        x=0;
        for ( int j = 0; j < n ; ++j ) {
            if (i&( 1<<j)){
                 x = x^arr[j];
            }     
        }
        sum = sum + x;

    }

		return sum;
    }
};