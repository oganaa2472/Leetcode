class Solution {
public:
    int n, windowSize;
    multiset<long long> minHalf;
    multiset<long long> maxHalf;

void adding(long long value)
{
    int currentMedian = *minHalf.rbegin(); // current median which is largest
    if (currentMedian < value)
    {
        maxHalf.insert(value);
        // balance
        if (maxHalf.size() > windowSize / 2)
        {
            minHalf.insert(*maxHalf.begin());
            maxHalf.erase(maxHalf.find(*maxHalf.begin()));
        }
    }
    else
    {
        minHalf.insert(value);
        // balance
        if (minHalf.size() > (windowSize + 1) / 2)
        {
            maxHalf.insert(*minHalf.rbegin());
            minHalf.erase(minHalf.find(*minHalf.rbegin()));
        }
    }
}

void removing(long long value)
{
    if (maxHalf.find(value) != maxHalf.end())
        maxHalf.erase(maxHalf.find(value));
    else
        minHalf.erase(minHalf.find(value));

    // lower portion has become empty
    if (minHalf.empty())
    {
        minHalf.insert(*maxHalf.begin());
        maxHalf.erase(maxHalf.find(*maxHalf.begin()));
    }
}
    // 2 4 5 6 7 
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
       windowSize= k;
       int n = nums.size();
        minHalf.insert(nums[0]);
        for (int i = 1; i < windowSize; i++)
            adding(nums[i]);

        vector<double> answer;
        if(k%2==0){
            double cur = double(*minHalf.rbegin()+*maxHalf.begin())/2;
            answer.push_back(cur);
        }else{
            answer.push_back(*minHalf.rbegin());
        }
        
        for(int i = windowSize;i<n;i++){
            if(windowSize==1){
                adding(nums[i]);
                removing(nums[i-windowSize]);
            }else{
                removing(nums[i-windowSize]);
                adding(nums[i]);
            }
             if(k%2==0){
                double cur = double(*minHalf.rbegin()+*maxHalf.begin())/2;
                answer.push_back(cur);
            }else{
                answer.push_back(*minHalf.rbegin());
            }
        }
        return answer;
    }
};