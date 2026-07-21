#include <algorithm>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [] (vector<int>& a, vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);

        for (vector<int> point: points) {
            minHeap.push(point);
        }

        vector<vector<int>> res;
        int bound = min(k, static_cast<int>(minHeap.size()));
        for (int i = 0; i < bound; i++) {
            vector<int> elem = minHeap.top();
            res.push_back(elem);
            minHeap.pop();
        }

        return res;
    }
};
