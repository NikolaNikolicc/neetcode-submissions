class Solution {
    int ROWS, COLS;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = '0';
        for (pair<int, int> dir: dirs) {
            int nr = dir.first + row, nc = dir.second + col;
            if (min(nr, nc) < 0 || nr >= ROWS || nc >= COLS || grid[nr][nc] != '1') continue;
            dfs(grid, nr, nc);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        ROWS = grid.size();
        COLS = grid[0].size();
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    res++;
                }
            }
        }
        return res;
    }
};
