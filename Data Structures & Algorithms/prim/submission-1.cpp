class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {

        unordered_map<int, vector<pair<int, int>>> adj;
        for (vector<int> edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        unordered_set<int> pathNodes;

        int mst = 0;

        // init
        for (auto [w, dst]: adj[0]){
            minHeap.push({w, dst});
        }
        pathNodes.insert(0);

        while (!minHeap.empty() && pathNodes.size() < n){
            auto [w1, v] = minHeap.top();
            minHeap.pop();

            if (pathNodes.count(v))continue;
            mst += w1;
            for (auto [w2, dst]: adj[v]){
                minHeap.push({w2, dst});
            }
            pathNodes.insert(v);
        }
        return (pathNodes.size() == n) ? mst : -1;
    }
};

