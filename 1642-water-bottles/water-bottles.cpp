class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
        while(numExchange<=numBottles){
            int temp = numBottles;
            int n = numBottles/numExchange;
            sum = sum + n ;
            numBottles=n;
            numBottles =numBottles+temp%numExchange;
        }
        return sum;
    }
};