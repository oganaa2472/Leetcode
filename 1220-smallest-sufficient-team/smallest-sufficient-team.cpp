class Solution {
public:
    int m;// skill count

    unordered_map<string, int> skill_index; // skill count saved for index for example java:0 nodejs:1 reactjs:2
    vector<int> people_skills; // saved peoples index to convert bit
    
    unordered_map<int, vector<int>> dp; 

    vector<int> solve(int mask){

        if (mask == (1 << m) - 1) return {}; // if you obtain all skills. 
        if (dp.count(mask)) return dp[mask]; // if you have already saved 

        

        vector<int> team; // find min team

        for(int i = 0;i<people_skills.size();i++){
            int current = people_skills[i];

            int new_mask = mask | current; //add current people 000|011 or 100 or 010  

            if((new_mask!=mask)) // if i would add new skill
            {
                vector<int> new_team = solve(new_mask);//check next team or moving next state
                new_team.push_back(i);// add current person 
                if (team.empty() || new_team.size() < team.size()) {// check minimum team you obtain it 
                    team = new_team; // you found min team
                }
            }
        }
        return dp[mask] = team;// saved dp 


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
        return solve(0);
    }
};