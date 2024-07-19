class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> rowMin(m, INT_MAX);
        vector<int> colMax(n, 0);
        
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                int el = matrix[row][col];
                rowMin[row] = min(rowMin[row], el);
                colMax[col] = max(colMax[col], el);
            }
        }
        
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                int el = matrix[row][col];
                if (el == rowMin[row] && el == colMax[col]) {
                    return {el};
                }
            }
        }
        
        return {};
    }
};