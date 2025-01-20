class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        stack<int> sta;
        // next greater element 
        for(int i = 0;i<n;i++){
            while(!sta.empty()&&temperatures[sta.top()]<temperatures[i]){
                result[sta.top()] = i-sta.top();
                sta.pop();
            }
            sta.push(i);
        }

        return result;
    }
};