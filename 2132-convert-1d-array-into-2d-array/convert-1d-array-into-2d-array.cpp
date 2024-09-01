class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n) return {};
        vector<vector<int>>ans(m, vector<int>(n));
        int start = 0, end = original.size()-1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(start <= end) ans[i][j] = original[start++];
            }
        }
        return ans;
    }
};