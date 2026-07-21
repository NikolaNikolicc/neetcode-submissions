class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int heapSize;
    
    KthLargest(int k, vector<int>& nums) {
        heapSize = k;
        for (int elem: nums) {
            minHeap.push(elem);
        }
        while (minHeap.size() > k) minHeap.pop();
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() < heapSize) return -1001;
        if (minHeap.size() > heapSize) minHeap.pop();
        return minHeap.top();
    }
};
