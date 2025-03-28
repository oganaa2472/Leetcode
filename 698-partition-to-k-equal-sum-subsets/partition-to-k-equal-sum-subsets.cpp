class Solution {
public:
    bool f(int i,vector<int> &nums,int tar,int sum,int k){

    if(k==0) return true;

    if(sum==tar){

        return f(0,nums,tar,0,k-1);

    }

    if(i>=nums.size()) return false;

    int t=false,nt=false;

    for(int j=i;j<nums.size();j++){

        if(nums[j]==-1) continue;

        if(nums[j]+sum<=tar){

            int ele=nums[j];

            nums[j]=-1;

            t=t||f(j+1,nums,tar,sum+ele,k);

            nums[j]=ele;

        }

    }

    return t;

}


    bool canPartitionKSubsets(vector<int>& arr, int k) {
        int sum=0;

        for(auto x:arr) sum+=x;

        if(sum%k!=0 || arr.size()<k) return false;

        sort(arr.begin(),arr.end(),greater<int>());

        return f(0,arr,sum/k,0,k);
    }
};
