#include <vector>
#include <cmath>
#include <numeric> // For std::accumulate
#include <iostream> // For cout (optional, for testing)

class Solution {
public:
    /**
     * @brief Checks if a number has exactly four divisors and sums them up if it does.
     *
     * A number has exactly four divisors if and only if:
     * 1. It is the cube of a prime number (p^3). Divisors: 1, p, p^2, p^3.
     * 2. It is the product of two distinct prime numbers (p1 * p2). Divisors: 1, p1, p2, p1*p2.
     *
     * The function iterates through potential divisors up to the square root of the number.
     * If a divisor 'i' is found, 'num / i' is also a divisor. By collecting all such
     * pairs (handling perfect squares carefully) we find all divisors.
     *
     * @param num The number to check.
     * @return The sum of divisors if num has exactly 4 divisors, otherwise 0.
     */
    int sumOfDivisorsIfFour(int num) {
        // A number less than 6 cannot have 4 divisors (1, 2, 3 have less, 4 has 3, 5 has 2).
        if (num < 6) {
            return 0;
        }

        std::vector<int> divisors;
        int limit = sqrt(num);

        // Iterate from 1 up to the square root of num to find divisors
        for (int i = 1; i <= limit; ++i) {
            if (num % i == 0) {
                // If i is a divisor, add it to the list
                divisors.push_back(i);

                // num / i is also a divisor. Add it if it's different from i.
                // This happens when num is not a perfect square (i*i != num)
                if (i * i != num) {
                    divisors.push_back(num / i);
                }
                 // Optimization: If we find more than 4 divisors, we can stop early.
                 // A number with more than sqrt(num) divisors will already have more than 2 divisors
                 // from pairs (i, num/i) where i < sqrt(num). If it's a perfect square,
                 // the middle divisor is counted once. Finding > 2 divisors up to sqrt(num)
                 // guarantees > 4 total divisors unless it's a perfect square counted once.
                 // A simpler early exit check: if we already have more than 4 divisors, this number
                 // won't qualify, so we can return 0 immediately.
                 if (divisors.size() > 4) {
                    return 0; // Has more than 4 divisors
                 }
            }
        }

        // After checking up to the square root, if we found exactly 4 divisors
        if (divisors.size() == 4) {
            // Calculate and return the sum of these 4 divisors
            int current_sum = 0;
            for (int d : divisors) {
                current_sum += d;
            }
            // Alternatively, using std::accumulate:
            // int current_sum = std::accumulate(divisors.begin(), divisors.end(), 0);
            return current_sum;
        } else {
            // The number does not have exactly 4 divisors
            return 0;
        }
    }

    /**
     * @brief Finds the sum of divisors of all integers in the input array
     * that have exactly four divisors.
     *
     * @param nums The input array of integers.
     * @return The total sum of divisors for qualifying numbers.
     */
    int sumFourDivisors(std::vector<int>& nums) {
        int total_sum_of_divisors = 0;

        // Iterate through each number in the input array
        for (int num : nums) {
            // Call the helper function to check and get the sum of divisors if it has 4
            total_sum_of_divisors += sumOfDivisorsIfFour(num);
        }

        return total_sum_of_divisors;
    }
};