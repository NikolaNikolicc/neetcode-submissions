class Solution {
    int ROWS;
    int COLS;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:

    int dfs(int r, int c, vector<vector<int>>& grid){
        if (min(r, c) < 0 || r >= ROWS || c >= COLS || !grid[r][c]){
            return 0;
        }

        grid[r][c] = 0;
        int maxArea = 0;
        for (pair<int, int> dir: this->dirs){
            maxArea += dfs(r + dir.first, c + dir.second, grid);
        }
        return maxArea + 1;
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
