class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0; // Эцсийн хариу
        
        for (int i = 0; i < 32; i++) { // 32 битээр давтах
            int bitCount = 0;
            int mask = (1 << i); // i-р байрлалын битийг ялгах маск
            
            for (int num : nums) { // Бүх тоог шалгах
                if (num & mask) { // Хэрэв i-р бит 1 байвал
                    bitCount++;
                }
            }
            
            if (bitCount > nums.size() / 2) { // 1 нь олонх бол
                majority |= mask; // i-р битийг 1 болгоно
            }
        }
        
        return majority;
    }
};