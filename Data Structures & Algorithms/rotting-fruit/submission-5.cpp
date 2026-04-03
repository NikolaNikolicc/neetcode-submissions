class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int, int>> rotten;

        int ROWS = grid.size(), COLS = grid[0].size();

        for (int r = 0; r < ROWS; r++){
            for (int c = 0; c < COLS; c++){
                if (grid[r][c] == 2) rotten.push({r, c});
                else if (grid[r][c] == 1)fresh++;
            }
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int timeElapsed = 0;
        while (!rotten.empty() && fresh){
            int ssize = rotten.size();
            for (int i = 0; i < ssize; i++){
                pair<int, int> r = rotten.front();
                rotten.pop();
                for (pair<int, int> dir: dirs){
                    int newR = r.first + dir.first, newC = r.second + dir.second;
                    if (min(newR, newC) < 0 || newR >= ROWS || newC >= COLS || grid[newR][newC] != 1){
                        continue;
                    }
                    rotten.push({newR, newC});
                    grid[newR][newC] = 2;
                    fresh--;
                }
            }
            timeElapsed++;
        }
        return (fresh) ? -1 : timeElapsed;
    }
};
