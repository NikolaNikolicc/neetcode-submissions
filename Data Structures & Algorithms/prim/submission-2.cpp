class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto &edge: edges) {
            adj[edge[0]].push_back({edge[2], edge[1]});
            adj[edge[1]].push_back({edge[2], edge[0]});
        }

        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 0});

        int mstSize = 0;
        while (visited.size() != n && minHeap.size() > 0) {
            pair<int, int> elem = minHeap.top();
            minHeap.pop();

            int dist = elem.first, src = elem.second;
            if (visited.count(src) > 0) continue;
            visited.insert(src);

            mstSize += dist;
            for (auto &[d, nei]: adj[src]) {
                if (visited.count(nei) == 0) minHeap.push({d, nei});
            }
        }

        return (visited.size() == n) ? mstSize : -1;
    }
};

