class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size()-k;
       
        while(left<right){
            int mid = (left+right)/2;
            if(x-arr[mid]>arr[mid + k] - x){
                left = mid+1;
            }else{
                right = mid;
            }
        }

        
       vector<int> sol(arr.begin() + left, arr.begin() + right + k);
        return sol;
    }
};