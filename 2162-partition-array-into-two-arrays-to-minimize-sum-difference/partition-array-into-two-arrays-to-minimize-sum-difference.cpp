class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        int res = INT_MAX,sum=0;
        // part1+part2=sum;
        sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> left(n+1),right(n+1);

        for(int i = 0;i<(1<<n);i++){
            int sz = 0,l=0,r=0;
            for(int j = 0;j<n;j++){
                if(i&(1<<j)){
                    sz++;
                    l+=nums[j];
                    r+=nums[j+n];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }
        for(int i  = 0;i<=n;i++){
            sort(left[i].begin(),left[i].end());
            sort(right[i].begin(),right[i].end());
        }
        res = min(abs(sum-2*left[n][0]),abs(sum-2*right[n][0]));
        for(int i =1;i<n;i++){
            for(auto& a: left[i]){
                int b = (sum - 2*a)/2,rightSize = n-i;
                auto& r = right[rightSize];
                auto it = lower_bound(r.begin(),r.end(),b);
                if(it!=r.end()){
                    res = min(res,abs(sum - 2*(a+(*it))));
                }
                if(it!=r.begin()){
                    auto itr = it;
                    itr--;
                    res = min(res,abs(sum - 2*(a+(*itr))));
                }
            }
        }
        return res;
    }
};