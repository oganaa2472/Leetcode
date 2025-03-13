class Solution {
public:
    vector<int> q;
    int n;
    bool check(int mid){
        
        int m = q.size();
        int sum = 0;
        for(int i=0;i<m;i++){
            double sk = double(q[i]/mid);
            int result = (q[i] + mid - 1) / mid;
            // cout<<result<<" ";
            sum += ceil(result);
        }
        cout<<endl;
        // cout<<sum<<" "<<mid<<" "<<m<<endl;
        return sum<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int right = *max_element(quantities.begin(),quantities.end());

        q = quantities;
        this->n=n;
        // if(n==1) return quantities[0];
        int left = 1;
        int ans = right;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(check(mid)){
                // cout<<mid<<" ";
                ans = min(ans,mid);
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};