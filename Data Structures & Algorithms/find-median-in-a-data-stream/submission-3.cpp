class MedianFinder {

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        if (minHeap.size() && minHeap.top() < maxHeap.top()) {
            int elem = maxHeap.top(); maxHeap.pop();
            minHeap.push(elem);
        }
        if ((int)minHeap.size() - (int)maxHeap.size() > 1) {
            int elem = minHeap.top(); minHeap.pop();
            maxHeap.push(elem);
        }
        if ((int)maxHeap.size() - (int)minHeap.size() > 1) {
            int elem = maxHeap.top(); maxHeap.pop();
            minHeap.push(elem);
        }
    }
    
    double findMedian() {
        if (minHeap.size() == 0 && maxHeap.size() == 0) {
            return -1.;
        }
        if (minHeap.size() > maxHeap.size()) {
            return minHeap.top();
        } else if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (minHeap.top() + maxHeap.top()) / 2.;
        }
    }
};
