struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0];
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> maxHeap; // bounded to k elements
        priority_queue<vector<int>, vector<vector<int>>, Compare> minHeap;

        for (int i = 0; i < profits.size(); i++) {
            minHeap.push({capital[i], profits[i]});
        }

        for (int i = 0; i < k; i++) {
            while (minHeap.size() && w >= minHeap.top()[0]) {
                vector<int> elem = minHeap.top(); minHeap.pop();
                maxHeap.push(elem[1]);
            }
            if (maxHeap.size() == 0) return w;
            int elem = maxHeap.top(); maxHeap.pop();
            w += elem;
        }

        return w;
    }
};