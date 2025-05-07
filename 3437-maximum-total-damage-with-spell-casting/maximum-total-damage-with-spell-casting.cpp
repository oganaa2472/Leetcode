#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iterator> // Required for std::prev

class Solution {
public:
    long long maximumTotalDamage(std::vector<int>& power) {
        std::unordered_map<int, long long> sum;
        for (int p : power) {
            sum[p] += p;
        }
        vector<long long> unique_powers;
        for (auto const& [p, total_damage] : sum) {
            unique_powers.push_back(p);
        }
        sort(unique_powers.begin(), unique_powers.end());

        
        map<long long, long long> dp;

       
        if (unique_powers.empty()) {
            return 0; 
        }

        
        dp[unique_powers[0]] = sum[unique_powers[0]];
        for (int i = 1; i < unique_powers.size(); ++i) {
            long long current_power = unique_powers[i];
            long long current_sum = sum[current_power];

            long long prev_power = unique_powers[i-1];
            long long max_damage_without_cur = dp[prev_power];

       
            long long max_damage_with_cur = current_sum;

            
            auto it = dp.lower_bound(current_power - 2);

            if (it != dp.begin()) {
                
                auto prev_it = std::prev(it);
                max_damage_with_cur += prev_it->second; 
            }


         
            dp[current_power] = max(max_damage_without_cur, max_damage_with_cur);
        }

     
        return dp[unique_powers.back()];
    }
};