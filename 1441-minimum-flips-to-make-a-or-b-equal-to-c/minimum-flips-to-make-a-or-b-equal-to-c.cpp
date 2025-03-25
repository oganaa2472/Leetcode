class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        // Check each bit position from 0 to 31 (assuming 32-bit integers)
        for (int i = 0; i < 32; i++) {
            // Extract the i-th bit of a, b, and c
            int a_bit = (a >> i) & 1;
            int b_bit = (b >> i) & 1;
            int c_bit = (c >> i) & 1;
            
            if (c_bit == 1) {
                // If c's bit is 1, we need at least one of a or b to be 1
                if (a_bit == 0 && b_bit == 0) {
                    flips += 1;  // We need to flip at least one of them to 1
                }
            } else {
                // If c's bit is 0, both a and b must be 0
                if (a_bit == 1) {
                    flips += 1;  // Flip a's bit to 0
                }
                if (b_bit == 1) {
                    flips += 1;  // Flip b's bit to 0
                }
            }
        }
        return flips;
    }
};