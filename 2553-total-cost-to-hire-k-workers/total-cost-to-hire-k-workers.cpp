class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long answer = 0;
        priority_queue<int,vector<int>,greater<int>> head;
         priority_queue<int,vector<int>,greater<int>> tail;
        //1,2
        //-2,-1
        for(int i = 0;i<candidates;i++){
            head.push(costs[i]);
            // 17,12,10
        }
        for(int i = max(candidates,(int)(costs.size()-candidates));i<costs.size();i++){
            tail.push(costs[i]);
        }
        int nextHead = candidates;
        int nextTail = costs.size()-1-candidates;
        for(int i = 0;i<k;i++){
            if(tail.empty()||!head.empty()&&head.top()<=tail.top()){
                answer = answer+(head.top());
                head.pop();
                if(nextHead<=nextTail){
                    head.push(costs[nextHead]);
                    nextHead++;
                }
            }else{
                answer+=(tail.top());
                tail.pop();
                if (nextHead <= nextTail) {
                    tail.push(costs[nextTail]);
                    nextTail--;
                }
            }
        }
        return answer;
    }
};