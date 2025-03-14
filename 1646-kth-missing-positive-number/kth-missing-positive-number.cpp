class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int n = arr.size();

        vector<int> missing(arr.size(),0);

        for(int i = 0;i<n;i++){
            missing[i] = arr[i]-(i+1);
            // cout<<missing[i]<<" ";
        }
        int right = n-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(missing[mid]<k){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        int more = k+right+1;
        
        // cout<<right;

        // if(arr[right-1]-right>k){

        //     while(left<=right-1){
        //         int mid = left+(right-mid)/2;
            
        //     }
        //     return 9;
        // }else{
        //     return arr[right-1]+k;
        // }
        return more;
        
        
    }
};