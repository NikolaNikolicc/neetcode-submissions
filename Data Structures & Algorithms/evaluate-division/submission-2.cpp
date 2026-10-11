class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        
        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        
        vector<double> result;
        for (const auto& query : queries) {
            unordered_set<string> visited;
            result.push_back(dfs(query[0], query[1], adj, visited));
        }
        return result;
    }

private:
    double dfs(const string& src, const string& target, 
               unordered_map<string, vector<pair<string, double>>>& adj,
               unordered_set<string>& visited) {
        // Check if source exists in graph
        if (adj.find(src) == adj.end()) return -1.0;
        
        // Found target
        if (src == target) return 1.0;
        
        visited.insert(src);
        
        for (const auto& [neighbor, weight] : adj[src]) {
            if (!visited.count(neighbor)) {
                double res = dfs(neighbor, target, adj, visited);
                if (res != -1.0) {
                    return res * weight;
                }
            }
        }
        
        return -1.0;
    }
};