class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++) {
            umap[i] = -1;
        }
        
        unordered_map<int, vector<pair<int, int>>> adj;
        for (vector<int> edge: edges) {
            adj[edge[0]].push_back({edge[2], edge[1]});
        }

        priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, src});

        int dist = 0;
        while (minHeap.size() > 0) {
            int d = minHeap.top().first, elem = minHeap.top().second; 
            minHeap.pop();
            if (umap[elem] != -1) continue;
            umap[elem] = d;

            for (auto &[dd, nei]: adj[elem]) {
                if (umap[nei] == -1) {
                    minHeap.push({d + dd, nei});
                }
            }
        }
        return umap;
    }
};
