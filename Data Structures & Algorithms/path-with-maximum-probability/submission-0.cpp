class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<double, int>>> adj;

        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            int from = edge[0], to = edge[1];
            double prob = succProb[i];
            adj[from].push_back({prob, to});
            adj[to].push_back({prob, from});
        }

        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1., start_node});
        
        unordered_set<int> visited;
        while (maxHeap.size()) {
            pair<double, int> elem = maxHeap.top(); maxHeap.pop();
            double prob = elem.first; 
            int from = elem.second;

            if (visited.count(from)) continue;
            visited.insert(from);

            if (from == end_node) return prob;

            for (auto &nei: adj[from]) {
                maxHeap.push({prob * nei.first, nei.second});
            }
        }
        return 0;
    }
};