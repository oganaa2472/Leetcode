class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        

        vector<int> sta;

        for(int a:ast){
            while(!sta.empty() && a<0&& sta.back()>0){
                int diff = a + sta.back();
                if(diff<0){
                    sta.pop_back();
                }else if(diff>0){
                    a = 0;
                }else{
                    a = 0;
                    sta.pop_back();
                }
            }
            if(a!=0){
                sta.push_back(a);
            }
        }
        return sta;
    }

};