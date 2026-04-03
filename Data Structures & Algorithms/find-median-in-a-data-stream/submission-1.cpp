class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minHeap.push(num);
        if (!maxHeap.empty() && minHeap.top() < maxHeap.top()){
            int tmp = minHeap.top();
            minHeap.pop();
            maxHeap.push(tmp);
        }

        if (minHeap.size() > maxHeap.size() + 1){
            int tmp = minHeap.top();
            minHeap.pop();
            maxHeap.push(tmp);
        }

        if (maxHeap.size() > minHeap.size() + 1){
            int tmp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(tmp);
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()){
            return (minHeap.top() + maxHeap.top()) / 2.0;
        } else if (minHeap.size() > maxHeap.size()){
            return (double)minHeap.top();
        } else return (double)maxHeap.top();
    }
};
