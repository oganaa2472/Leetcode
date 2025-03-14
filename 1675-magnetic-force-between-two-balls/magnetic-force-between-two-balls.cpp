class Solution {
public:

    bool check(int mid,vector<int>& p,int m ){
        int count = 1;
        int lastPos = p[0];
        int n = p.size();
        for(int i = 1;i<n;i++){
            if(p[i]-lastPos>=mid){
                count++;
                lastPos = p[i];
            }
        }
        return count>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());  

        int left = 1, right = position.back() - position.front(); 

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, position, m)) {
                left = mid + 1;  
            } else {
                right = mid - 1; 
            }
        }
        return right;
    }
};