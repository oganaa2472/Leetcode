class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int j = 1;
        int n = num_people;
        vector<int> v(num_people);
        cout<<v.size();
        int i = 0;
        int sum = 0;
        while(sum+j<candies){
            
            sum = sum + j;
            v[i] += j;
            j++;
            i++;
            if(i==n) i = 0;  
        }
        cout<<sum<<" ";
        if(candies-sum>0){
            v[i]=v[i]+(candies-sum);
        }
        return v;
    }
};