class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;

        int maxa = 0;
        while (l < r){
            int a = (r - l) * min(heights[r], heights[l]);
            maxa = max(maxa, a);
            if (heights[l] < heights[r]){
                l++;
            } else {
                r--;
            }

        }

        return maxa;
    }
};
