#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        vector<pair<int, int>> pixels;

        if (color == startColor) return image;
        pixels.push_back({sr, sc});

        vector<pair<int, int>> dirs = {
            {0, -1},
            {-1, 0},
            {0, 1},
            {1, 0}
        };
        image[sr][sc] = color;
        while (pixels.size() > 0) {
            pair<int, int> p = pixels.back();
            pixels.pop_back();
            int r = p.first, c = p.second;

            int ROWS = image.size(), COLS = image[0].size();
            
            cout << "Processing pixel: (" << r << ", " << c << ")" << endl;
            for (pair<int, int> d: dirs) {
                int dr = d.first, dc = d.second;
                int nr = r + dr, nc = c + dc;

                cout << "Checking neighbor: (" << nr << ", " << nc << ")" << endl;
                if (min(nr, nc) >= 0 && nr < ROWS && nc < COLS && image[nr][nc] == startColor) {
                    image[nr][nc] = color;
                    pixels.push_back({nr, nc});
                }
            }
        }
        return image;
    }
};