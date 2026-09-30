class Solution {
public:
    vector<int> q;
    int n;
    bool check(int mid){
        
        int m = q.size();
        int sum = 0;
        for(int i=0;i<m;i++){
          
            int result = (q[i] + mid - 1) / mid;
            sum +=result;
        }
        return sum<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int right = 1e9;

        q = quantities;
        this->n=n;
        // if(n==1) return quantities[0];
        int left = 1;
        int ans = INT_MAX;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(check(mid)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};