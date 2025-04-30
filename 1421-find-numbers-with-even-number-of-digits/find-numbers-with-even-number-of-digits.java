class Solution {
    public int findNumbers(int[] nums) {
        int c = 0;
        for(int i = 0;i<nums.length;i++){
            int  a = nums[i];
            int j = 0;
            while(a>0){
                a=a/10;
                j++;
            }
            if(j%2==0){
                c++;
            }
        }
        return c;
    }
}