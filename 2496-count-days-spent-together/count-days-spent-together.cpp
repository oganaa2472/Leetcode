class Solution {
public:
  
   int totalDays(const string& date) {
        
        const vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));   

        // Calculate the day of the year
        int dayOfYear = 0;
        for (int i = 0; i < month - 1; i++) {
            dayOfYear += daysInMonth[i];
        }
        dayOfYear += day;
        return dayOfYear;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        
        int x1 = totalDays(arriveAlice);
        int y1 = totalDays(leaveAlice);
        int x2 = totalDays(arriveBob);
        int y2 = totalDays(leaveBob);

        int overlapStart = max(x1,x2);
        int overlapEnd = min(y2,y1);
        if(overlapStart>overlapEnd){
            return 0;
        }else{
            return  overlapEnd-overlapStart +1;
        }
        // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        // return max({0,(y1+1-x2)});
    }
};