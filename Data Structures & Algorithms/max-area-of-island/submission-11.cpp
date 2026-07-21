class Solution {
    int ROWS, COLS;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:

    int dfs(int row, int col, vector<vector<int>>& grid) {
        int area = 1;
        grid[row][col] = 0;
        for (pair<int, int> dir: dirs) {
            int nr = row + dir.first, nc = col + dir.second;
            if (min(nr, nc) >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == 1) {
                area += dfs(nr, nc, grid);
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->ROWS = grid.size();
        this->COLS = grid[0].size();
        int area = 0;
        for (int r = 0; r < this->ROWS; r++){
            for (int c = 0; c < this->COLS; c++){
                if (grid[r][c]) area = max(area, dfs(r, c, grid));
            }
        }
        return area;
    }
};
