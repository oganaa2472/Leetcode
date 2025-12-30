class MedianFinder
{
    priority_queue<int> s;
    priority_queue<int,vector<int>,greater<int>> l;
    unordered_map<int,int> delayed;
    int S=0,L=0;
    int k;
    void lazyDeleteS(priority_queue<int> &pq)
    {
        //it will only pop if we reach the point where num is there
        while(!pq.empty() && delayed[pq.top()])
        {
            delayed[pq.top()]--;
            pq.pop();
        }
    }
    void lazyDeleteL(priority_queue<int,vector<int>,greater<int>> &pq)
    {
        //it will only pop if we reach the point where num is there
        while(!pq.empty() && delayed[pq.top()])
        {
            delayed[pq.top()]--;
            pq.pop();
        }
    }
    void balance(int d)
    {
        if(d>1)
        {
            l.push(s.top());s.pop();
            S--;
            L++;
        }
        if(d<0)
        {
            s.push(l.top());l.pop();
            S++;
            L--;
        }
        lazyDeleteS(s);
        lazyDeleteL(l);
    }
    public:
    MedianFinder(int k)
    {
        while(!s.empty()) s.pop();
        while(!l.empty()) l.pop();
        delayed.clear();
        S=L=0;
        this->k=k;
    }
    void add(int x)
    {
        if(s.empty() || x<s.top()) 
        {
            s.push(x);S++;
        }
        else 
        {
            l.push(x);L++;
        }
        balance(S-L);
    }
    void remove(int x)
    {
        delayed[x]++;
        if(!s.empty() && x<=s.top()) S--;
        else L--;
        balance(S-L);
    }
    double Median()
    {
        lazyDeleteS(s);
        lazyDeleteL(l);
        if(k%2==1) return s.top();
        else return ((double)s.top() + (double)l.top()) / 2.0;
    }
};
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        MedianFinder mf(k);
        vector<double> res;
        for(int i=0;i<nums.size();i++)
        {
            mf.add(nums[i]);
            if(i>=k-1)
            {
                res.push_back(mf.Median());
                mf.remove(nums[i-k+1]);
            }
        }
        return res;
    }
};