class NumMatrix {
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sums = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int r = 0; r < matrix.size(); r++) {
            int prefix = 0;
            for (int c = 0; c < matrix[0].size(); c++) {
                prefix += matrix[r][c];
                int sumAbove = (r) ? sums[r - 1][c] : 0;
                sums[r][c] = sumAbove + prefix;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int bottomRight = sums[row2][col2];
        int bottomLeft  = (col1) ? sums[row2][col1 - 1] : 0;
        int upperRight  = (row1) ? sums[row1 - 1][col2] : 0;
        int upperLeft   = (row1 && col1) ? sums[row1 - 1][col1 - 1] : 0;
        return bottomRight - bottomLeft - upperRight + upperLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */