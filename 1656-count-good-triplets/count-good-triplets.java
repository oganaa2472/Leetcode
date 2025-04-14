class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        if(arr == null || arr.length<3)return 0;
        int i,j,k,cnt=0,n=arr.length;
        for(i=0;i<n-2;i++){
            for(j=i+1;j<n-1;j++){
                for(k=j+1;k<n;k++){
                    if(Math.abs(arr[i]-arr[j])<=a && Math.abs(arr[j]-arr[k])<=b && Math.abs(arr[i]-arr[k])<=c){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
}