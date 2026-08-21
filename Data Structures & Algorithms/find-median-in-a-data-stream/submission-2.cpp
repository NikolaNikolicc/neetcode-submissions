class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minHeap.push(num);
        if (!maxHeap.empty() && minHeap.top() < maxHeap.top()) {
            int elem = minHeap.top();
            minHeap.pop();
            maxHeap.push(elem);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            int elem = maxHeap.top();
            maxHeap.pop();
            minHeap.push(elem);
        }

        if (minHeap.size() > maxHeap.size() + 1) {
            int elem = minHeap.top();
            minHeap.pop();
            maxHeap.push(elem);
        }
    }
    
    double findMedian() {
        if (minHeap.size() > maxHeap.size()) return minHeap.top();
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();

        return (minHeap.top() + maxHeap.top()) / 2.0;
    }
};
