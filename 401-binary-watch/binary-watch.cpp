class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        // 4 time, 6 minute total 10 bits hhhhmmmmmm
        for(int mask =0;mask<1024;mask++){
            int hours = mask >> 6;                 // Эхний 4 бит → цаг
            int minutes = mask & 0b111111; // last six digit

            if(__builtin_popcount(mask)==turnedOn&&hours<12&&minutes<60){
                result.push_back(to_string(hours)+":"+(minutes < 10 ? "0" : "") + to_string(minutes));
            }
        }
        return result;
    }
};