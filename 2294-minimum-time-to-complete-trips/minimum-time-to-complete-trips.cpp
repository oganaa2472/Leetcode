class Solution {
public:
    bool check(long long mid,vector<int>& time,int k){
        
       long long trips = 0;
        
        for (int t : time) {
            trips += mid / t;
            if (trips >= k) {
                return true;
            }
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
       long long left = 1, right = (long long) *min_element(time.begin(), time.end()) * totalTrips;
    
      
  
       while (left < right) {
        long long mid = (left + right) / 2;
        long long trips = 0;
        
        for (int t : time) {
            trips += mid / t;
            if (trips >= totalTrips) break; // Хэтэрхий их тооцоолохоос сэргийлэх
        }
        
        if (trips >= totalTrips)
            right = mid;
        else
            left = mid + 1;
    }
    
    return left;
    }
};