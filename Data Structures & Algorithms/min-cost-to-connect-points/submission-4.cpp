

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        auto manhatn = [](vector<int> &a, vector<int> &b) {
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };

        unordered_map<int, unordered_map<int, int>> adj;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j < i) {
                    // use cache
                    adj[i][j] = adj[j][i];
                } else if (j == i) {
                    continue;
                } else {
                    // calculate
                    adj[i][j] = manhatn(points[i], points[j]);
                }
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        unordered_set<int> visited;
        

        minHeap.push({0, 0});

        int mstSize = 0;
        while (minHeap.size() > 0 && visited.size() != n) {

            pair<int, int> elem = minHeap.top(); minHeap.pop();
            int distance = elem.first, idx = elem.second;

            if (visited.count(idx) > 0) continue;
            visited.insert(idx);

            mstSize += distance;

            for (auto &[key, value]: adj[idx]) {
                if (visited.count(key) == 0) minHeap.push({value, key});
            }
        }
        return mstSize;
    }
};
