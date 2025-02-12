class Solution {
public:
    int convertSum(int i){
        int sum=0;
        while(i>0){
            int m=i%10;
            sum+=m;
            i/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>> digit;
        int n = nums.size();
        for(int i =0;i<n;i++){
           digit[convertSum(nums[i])].push_back(nums[i]);
        }  
        
        vector<int> v;
        int answer = 0;
        bool isCheck =true;
        for(auto it = digit.rbegin();it!=digit.rend();it++){
            if(it->second.size()>=2){
                v=it->second;
                isCheck = false;
                sort(v.begin(),v.end());
                answer = max(answer,v[v.size()-1]+v[v.size()-2]);
            }
        }
        if(!isCheck){
            return answer;
        }
        //     sort(v.begin(),v.end());
        //     return v[v.size()-1]+v[v.size()-2];
        // }
        return -1;
    }
};