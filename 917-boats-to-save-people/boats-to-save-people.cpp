class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());


        int answer = 0;
        int i = 0;
        int j = people.size()-1;
        while(i<=j){
            while(people[j]==limit){
                j--;
                answer++;
            }
            int sum = people[i]+people[j];
            
            if(limit<sum){
                answer++;
                j--;
            }else{
                i++;
                j--;
                answer++;
                // while(sum+people[i]<=limit){
                //     i++;
                //     sum = sum+people[i];
                // }
                
                
            }
        }
        return answer;
    }
};