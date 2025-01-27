class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        

        stack<int> sta;
    
        for(int i=0;i<a.size();i++){
            
            if(sta.empty()) {
                sta.push(a[i]);
            }
            else{
                int top = sta.top();
                if(top>0&&a[i]>0){
                    sta.push(a[i]);
                }else if(top<0&&a[i]<0){
                    sta.push(a[i]);
                }else{
                    if(top>0){
                        
                        if(0==top+a[i]) sta.pop();
                        else{
                           
                        while(!sta.empty()&&top>0&&top+a[i]<0){
                                
                                sta.pop();
                                if(sta.empty())break;
                                top = sta.top();
                            }
                            if(sta.empty()){
                               sta.push(a[i]);
                            }
                            else if(top<0){
                                sta.push(a[i]);
                            }else if(top+a[i]==0){
                                sta.pop();
                            }
                        }
                        

                       
                         
                        
                    }else{
                        sta.push(a[i]);
                    }
                }
            }
        }   
        int size = sta.size();
        vector<int> answer(size,0);
        while(!sta.empty()){
            int peek = sta.top();
            answer[size-1] = peek;
            size--;
            sta.pop();
        }
        return answer;
    }
};