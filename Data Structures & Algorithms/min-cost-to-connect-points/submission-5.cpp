class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);
        minDist[0] = 0;
        int total = 0;

        for (int iter = 0; iter < n; iter++) {
            int u = -1;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && (u == -1 || minDist[i] < minDist[u]))
                    u = i;
            }
            visited[u] = true;
            total += minDist[u];

            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int d = abs(points[u][0] - points[v][0]) +
                            abs(points[u][1] - points[v][1]);
                    minDist[v] = min(minDist[v], d);
                }
            }
        }
        return total;
    }
};