class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        Arrays.sort(arr2);
        
        int ans = 0;
        for(int j:arr1){
            int z=bs(arr2,j,d);
            if(z!=0){
                ans+=1;
            }
        }
        return ans;
    }
     static int bs(int[] arr,int t, int d) {
        int start=0;
        int end=arr.length-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(Math.abs(t-arr[mid]) <= d){
                return 0;
            }
            if(arr[mid]<=t){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
}