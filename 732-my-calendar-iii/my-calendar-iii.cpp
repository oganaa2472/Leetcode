class MyCalendarThree {
public:
    map<int, int> diff;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        diff[startTime]++;

        // Event ends
        diff[endTime]--;

        int active = 0;
        int ans = 0;

        for (auto &it : diff) {
            active += it.second;
            ans = max(ans, active);
        }

        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */