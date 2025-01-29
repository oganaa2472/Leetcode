class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    
        vector<pair<int, double> > p1;
        
        int n = position.size();
        for(int i = 0;i<n;i++){
            p1.push_back(make_pair(position[i],(double)(target-position[i])/speed[i]));
        }
        sort(p1.begin(),p1.end());
        int t = n;
        int ans = 1;
        while(--t>0){
            if(p1[t].second<p1[t-1].second){
                ans++;
            }else{
                p1[t-1] = p1[t];
            }
            // t--;

            
        }

        // if(t==0) ans++;
        return ans;
    }
};