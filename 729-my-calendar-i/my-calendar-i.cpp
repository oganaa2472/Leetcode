class MyCalendar {
public:
    // {20:10},
    map<int,int> intervals;
    MyCalendar() {
        intervals.clear();
    }
    
    bool book(int startTime, int endTime) {

        auto lower = intervals.upper_bound(startTime);
        // find nearest end time;
        if(lower!=intervals.end()){
            cout<<lower->first<<" "<<lower->second<<endl;
            int nearestStart = lower->second;
            int duration = endTime-startTime;
            if(duration+startTime>nearestStart){
                return false;
            }
            // if(nearestStart<=endTime&&nearestEnd>endTime){
            //     return false;
            // }
        }
        intervals[endTime] = startTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */