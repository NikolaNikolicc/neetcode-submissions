class Solution {
public:
    int maxArea(vector<int>& heights) {
        auto area = [](int h1, int h2, int i1, int i2) {
            return (i2 - i1) * min(h1, h2);
        };

        int l = 0, r = heights.size() - 1;
        int res = 0;
        while (l < r) {
            res = max(res, area(heights[l], heights[r], l, r));
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};
