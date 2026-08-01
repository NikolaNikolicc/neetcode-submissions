class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> rightPass(size, 0);
        vector<int> leftPass(size, 0);

        int agg = 0;
        for (int i = 0; i < size; i++) {
            agg = max(agg, height[i]);
            rightPass[i] = agg;
        }
        agg = 0;
        for (int i = size - 1; i >= 0; i--) {
            agg = max(agg, height[i]);
            leftPass[i] = agg;
        }

        int area = 0;
        for (int i = 0; i < size; i++) {
            area += min(rightPass[i], leftPass[i]) - height[i];
        }
        return area;
    }
};
