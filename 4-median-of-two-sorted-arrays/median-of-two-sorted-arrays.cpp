class Solution {
public:
    multiset<int> s;
    multiset<int>::iterator mid;
    void insertX(int x) {
        s.insert(x);
        if (s.size() == 1) {
            mid = s.begin(); // Эхний элемент дунд нь
            return;
        }

        if (x < *mid) {
            if (s.size() % 2 == 0) --mid; // Дараалал тэгш бол буцаана
        } else {
            if (s.size() % 2 == 1) ++mid; // Дараалал сондгой бол урагшлуулна
        }
    }

    int getMedian() {
        return *mid;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        for(int i = 0;i<nums1.size();i++){
            insertX(nums1[i]);
        }
        for(int i = 0;i<nums2.size();i++){
            insertX(nums2[i]);
        }
        if(s.size()%2==1) return getMedian();
        double x = getMedian();
        mid++;
        double y = getMedian();
        return (x+y)/2;
    }
};