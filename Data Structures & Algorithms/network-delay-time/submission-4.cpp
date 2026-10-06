class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto &t: times) {
            int from = t[0], to = t[1], time = t[2];
            adj[from].push_back({time, to});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int cnt = n;
        minHeap.push({0, k});
        vector<bool> visited(n + 1, false);
        int minTime = INT_MAX;
        while (cnt > 0 && minHeap.size() > 0) {
            int dist = minHeap.top().first, src = minHeap.top().second;
            minHeap.pop();

            if (visited[src]) continue;
            minTime = dist;
            cnt--;
            visited[src] = true;
            for (auto &[distance, nei]: adj[src]) {
                minHeap.push({dist + distance, nei});
            }
        }
        return (cnt == 0) ? minTime : -1;
    }
};
