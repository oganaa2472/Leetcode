class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int result=0;

        for(int mask = 0;mask<32;mask++){
            
            int sum = 0;

            for (int num : nums) {
                if (num & (1 << mask)) {  // i-р бит 1 эсэхийг шалгах
                    sum++;
                }
            }

            
            if (sum % 3 != 0) {
                result |= (1 << mask);   // i-р битийг 1 болгоно
            }
        
        }
        return result;
    }
};