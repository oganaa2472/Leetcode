class Solution {
public:
    int minFlips(int a, int b, int c) {
        int answer = 0;
        for(int i = 0;i<31;i++){
            int abitValue = (a & (1 << (i))) != 0 ? 1 : 0;
            int bbitValue = (b & (1 << (i))) != 0 ? 1 : 0;
            int cbitValue = (c & (1 << (i))) != 0 ? 1 : 0;
            if(cbitValue==0){
                answer+=abitValue+bbitValue;
            }else{
                int cur = abitValue|bbitValue;
                if(cur==0) answer++;
            }
        }
        return answer;
    }
};