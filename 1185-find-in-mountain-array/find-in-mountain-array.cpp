/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();
        int low = 0;
        int high = length-1;

        int peak;
        int mid = (low+high)/2;
        
        while(low<high){
            int mid = (low+high)/2;
            int fval = mountainArr.get(mid);
            int sval = mountainArr.get(mid+1);
            if(fval<sval){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        peak = low;

        low = 0;
        high = peak;
        int answer = -1;
        while(low<=high){
            int mid = (low+high)/2;

            if(mountainArr.get(mid)==target){
                answer = mid;
                break;
            }else if(mountainArr.get(mid)>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        if(answer!=-1){
            return answer;
        }else{
            high = peak;
            low = length-1;

            while(high<=low){
                int mid = (low+high)/2;
                if(mountainArr.get(mid)==target){
                    answer = mid;
                    break;
                }else if(mountainArr.get(mid)>target){
                    high = mid+1;
                }else{
                    low = mid-1;
                }
            }
            return answer;
        }

       

    }
};