class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> freq;
        for(auto c:tasks) freq[c]++;
        priority_queue<int> pq;
        for(auto [c,cnt]:freq){
            pq.push(cnt);
        }   
        int time = 0;
        int cycle = n+1;
        while(!pq.empty()){        
            vector<int> store;
            cycle = n+1;
            int taskCount= 0;
            while(cycle>0&&!pq.empty()){
                cycle--;
                if(pq.top()>1)
                    store.push_back(pq.top()-1);
                pq.pop();
                taskCount++;
            }
        
            for(int i = 0;i<store.size();i++){
                pq.push(store[i]);
            }
            if(!pq.empty()) time+=n+1;
            else time+= taskCount;
        }
        return time;

        
    }
};