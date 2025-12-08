class Solution {
public:
    int pivotInteger(int n) {
        int sum = n *(n+1) /2;
	
        for(int i =1;i<=n;i++){
            int a = i * (i+1) /2;
            int b = sum - a + i;

            if(a==b) {
                cout<<i<<endl;
                return i;
            }
        }
	    return -1;
    }
};