class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,long long> sum;
        vector<long long> unique;
        for (int p : power) {
            sum[p] += p;
        }
       
        for (auto const& [p, total_damage] : sum) {
            unique.push_back(p);
        }
     
        if(unique.empty()) return 0;
        sort(unique.begin(),unique.end());
        int n = unique.size();
        map<long long,long long> dp;
        dp[unique[0]] = sum[unique[0]];
        for (int i = 1; i < unique.size(); ++i) {
            long long current_power = unique[i];
            long long current_sum = sum[current_power];

            long long prev_power = unique[i-1];
            long long max_damage_without_cur = dp[prev_power];

       
            long long max_damage_with_cur = current_sum;

            
            auto it = dp.lower_bound(current_power - 2);

            if (it != dp.begin()) {
                
                auto prev_it = std::prev(it);
                max_damage_with_cur += prev_it->second; 
            }


         
            dp[current_power] = max(max_damage_without_cur, max_damage_with_cur);
        }
        return dp[unique.back()];
    }
};