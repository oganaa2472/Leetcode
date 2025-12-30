#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
private:
    priority_queue<long long> maxHeap; // жижиг талын элементүүд
    priority_queue<long long, vector<long long>, greater<long long>> minHeap; // том талын элементүүд
    unordered_map<long long,int> delayed; // lazy removal

    int smallSize = 0, largeSize = 0;

    void pruneMaxHeap() {
        while (!maxHeap.empty() && delayed[maxHeap.top()]) {
            delayed[maxHeap.top()]--;
            maxHeap.pop();
        }
    }

    void pruneMinHeap() {
        while (!minHeap.empty() && delayed[minHeap.top()]) {
            delayed[minHeap.top()]--;
            minHeap.pop();
        }
    }

    void balance() {
        if (smallSize > largeSize + 1) {
            long long top = maxHeap.top(); maxHeap.pop();
            smallSize--;
            minHeap.push(top); largeSize++;
            pruneMaxHeap();
        } else if (smallSize < largeSize) {
            long long top = minHeap.top(); minHeap.pop();
            largeSize--;
            maxHeap.push(top); smallSize++;
            pruneMinHeap();
        }
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;

        // Эхний цонх
        for (int i = 0; i < k; i++) {
            long long num = nums[i];
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
                smallSize++;
            } else {
                minHeap.push(num);
                largeSize++;
            }
            balance();
        }

        // Эхний median
        if (k % 2 == 1) result.push_back(maxHeap.top());
        else result.push_back((maxHeap.top() + minHeap.top()) / 2.0);

        // Цонхыг гүйлгэх
        for (int i = k; i < nums.size(); i++) {
            long long addNum = nums[i];
            long long removeNum = nums[i - k];

            // Шинэ элемент нэмэх
            if (addNum <= maxHeap.top()) { maxHeap.push(addNum); smallSize++; }
            else { minHeap.push(addNum); largeSize++; }

            // Хуучин элементийг lazy remove
            delayed[removeNum]++;
            if (removeNum <= maxHeap.top()) smallSize--;
            else largeSize--;

            balance();
            pruneMaxHeap();
            pruneMinHeap();

            // Median авах
            if (k % 2 == 1) result.push_back(maxHeap.top());
            else result.push_back((maxHeap.top() + minHeap.top()) / 2.0);
        }

        return result;
    }
};
