class Solution {
public:
    int getNext(int n){
        int sum = 0;
        while(n>0){
            int d = n%10;
            n=n/10;
            sum = sum+d*d;
        }
        return sum;
        
    }
    bool isHappy(int n) {
        unordered_set<int> seen;

        while(n!=1&&seen.count(n)==0){
            seen.insert(n);
            n = getNext(n);
        }
        return n==1;
    }
};