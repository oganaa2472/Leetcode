class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](
            const vector<int>& a ,const vector<int> b
        ){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
    
        vector<int> answer;
        for(auto e:envelopes){
            if(answer.size()==0 || e[1]>answer.back()){
                answer.push_back(e[1]);
            }else{
                int index = lower_bound(answer.begin(),answer.end(),e[1])-answer.begin();
                answer[index] = e[1];
            }
           
        }
        return (int)answer.size();
        
    }
};