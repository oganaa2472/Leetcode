class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0,totalCost = 0;
        for(int val : gas){
            totalGas+=val;
        }
        for(int val:cost){
            totalCost+=val;
        }
        if(totalGas<totalCost){
            return -1;
        }
        int currentGas = 0;
        int start = 0;
        for(int i=0;i<gas.size();i++){
            currentGas += gas[i]-cost[i];
            if(currentGas<0){
                currentGas = 0;
                start = i+1;
            }
        }
        return start;
    }
};