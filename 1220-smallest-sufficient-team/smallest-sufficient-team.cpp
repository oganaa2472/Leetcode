class Solution {
public:
    unordered_map<string,int> skill_index;
    vector<int> people_skills;
    int m;
    int req;
    unordered_map<int,vector<int>> dp;
    vector<int> solve(int mask){
        if(req==mask){
            return {};
        }
        if (dp.count(mask)) return dp[mask];


        vector<int> team; 
        for(int i = 0;i<people_skills.size();i++){
            int current = people_skills[i];
            int new_mask = mask | current;
            if(new_mask!=mask){
                vector<int> new_team = solve(new_mask);
                new_team.push_back(i);
                if(team.empty() || new_team.size() < team.size()){
                    team = new_team;
                }
            }
        }
        return dp[mask] = team;

    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        m = req_skills.size();
        for(int i = 0;i<m;i++){
            skill_index[req_skills[i]] = i;
        }
        for (auto& person : people) {
            int mask = 0;
            for (auto& skill : person) {
                // cout<<skill_index[skill];
                mask |= (1 << skill_index[skill]); // person skill convert to bit 
            }
            // cout<<endl;
            people_skills.push_back(mask);
        }
        req = (1<<m)-1;
        return solve(0);

    }
};