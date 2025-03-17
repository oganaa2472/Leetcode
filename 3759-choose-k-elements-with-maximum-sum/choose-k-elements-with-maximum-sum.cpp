#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<ll,ll>> a;
        for(int i = 0;i<n;i++){
            a.push_back({
                nums1[i],i
            });
        }
        sort(a.begin(),a.end());
        long long sum = 0;
        vector<ll> pending;
        vector<ll> result(n,0);
        
        multiset<ll> ord;
        for(int i = 0;i<n;i++){

            long long idx = a[i].second;
            long long val = nums2[idx];
            result[idx] = sum;
           
            pending.push_back(val);
            if(i<n-1&&a[i].first==a[i+1].first) continue;

            for(auto &v:pending){
                if(ord.size()<k){
                    sum +=v;
                    ord.insert(v); 
                }else if(*ord.begin()<v){
                    sum -=*ord.begin();
                    ord.erase(ord.begin());
                    ord.insert(v); 
                    sum +=v;
                    
                }
            }
            pending.clear();
        }
        return result;
    }
};