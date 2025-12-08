class Solution {
    public boolean isPalindrome(int x) {
        int a = x;
        int res = 0;
        if(x<0){
            return false;
        }
        else
        while(x!=0){
            int divid = x%10;
            res = res * 10 + divid;
            x=x/10;
        }
        
        if(res==a){
            return true;
        }
        else{
            return false;
        }
    }
}