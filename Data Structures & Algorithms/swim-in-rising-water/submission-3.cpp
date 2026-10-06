struct Comparator {
    bool operator()(vector<int> &a, vector<int> &b) {
        return a[0] > b[0];
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, Comparator> minHeap;
        set<pair<int, int>> visited;
        int ROWS = grid.size(), COLS = grid[0].size();
        minHeap.push({grid[0][0], 0, 0});
        int minHeight = INT_MIN;

        vector<pair<int, int>> directions = {
            {-1, 0}, {0, -1}, {1, 0}, {0, 1}
        };
        
        while (minHeap.size() > 0) {
            vector<int> elem = minHeap.top(); 
            int height = elem[0], x = elem[1], y = elem[2];
            minHeap.pop();

            if (visited.count({x, y})) continue;

            visited.insert({x, y});
            minHeight = max(minHeight, height);
            if (x == ROWS - 1 && y == COLS - 1) return minHeight;

            for (auto &[dx, dy]: directions) {
                int nx = x + dx, ny = y + dy;
                if (min(nx, ny) < 0 || nx >= ROWS || ny >= COLS)continue;
                minHeap.push({grid[nx][ny], nx, ny});
            }  
        }
        return minHeight;
    }
};
