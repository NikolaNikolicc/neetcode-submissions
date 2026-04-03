class Solution {
private:
    unordered_map<int, vector<int>> adj;
    vector<int> order;
    unordered_set<int> path;
    unordered_set<int> visited;

    bool topo(int node){
        if (path.count(node)){
            return false;
        }

        if (visited.count(node)){
            return true;
        }
        
        visited.insert(node);
        path.insert(node);
        for (int nei: adj[node]){
            if (!topo(nei)){
                return false;
            }
        }
        path.erase(node);
        

        order.push_back(node);
        return true;

    }
    
public:
    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
        for (vector<int> edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }

        for (int i = 0; i < n; i++){
            if (!topo(i)){
                return vector<int>();
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};
