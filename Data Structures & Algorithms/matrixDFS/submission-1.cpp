class Solution {
private:
    int ROWS;
    int COLS;
    vector<pair<int, int>>directions;
    
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c){
        if (r == ROWS - 1 && c == COLS - 1 && !grid[r][c]){
            return 1;
        }
        
        if (min(r, c) < 0 || r >= ROWS || c >= COLS || grid[r][c] || visited[r][c]){
            return 0;
        }

        int cnt = 0;
        visited[r][c] = 1;
        for(pair<int, int> dir: directions){
            cnt += dfs(grid, visited, r + dir.first, c + dir.second);
        } 
        visited[r][c] = 0;
        return cnt;
    }

    int countPaths(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        directions = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
        vector<vector<int>> visited(ROWS, vector<int>(COLS, 0));
        return dfs(grid, visited, 0, 0);
    }
};
