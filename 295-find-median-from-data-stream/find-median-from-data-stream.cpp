class MedianFinder {
public:
    std::priority_queue<int> maxHeap; // Max heap for the lower half
    // 1 2 3 
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; 
    // 6 5 3
    // Min heap for the upper half

    // 1,2,3,4
    // max: 1 2
    // min: 4 3
    MedianFinder() {
       

    }
    //2 3   345
    void addNum(int num) {
         maxHeap.push(num); 
        minHeap.push(maxHeap.top()); 
        maxHeap.pop();
        if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        int m = minHeap.size();
        int n = maxHeap.size();
        if(n==m){
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }else return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */