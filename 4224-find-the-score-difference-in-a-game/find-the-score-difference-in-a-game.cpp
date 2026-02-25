class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int finalScore=0;
        bool playerTurn=false;
        //playerTurn=false==1st player turn
        //playerTurn=true==2nd player turn
        for(int i=0;i<nums.size();i++){
            int scoreToBeAdded=nums[i];
            if(scoreToBeAdded&1)playerTurn=!playerTurn;
            if(i%6==5)playerTurn=!playerTurn;
            if(playerTurn)finalScore-=scoreToBeAdded;
            else finalScore+=scoreToBeAdded;
        }
        return finalScore;
    }
};