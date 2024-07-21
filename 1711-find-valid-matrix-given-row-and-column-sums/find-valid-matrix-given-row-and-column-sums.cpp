class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();

        vector<vector<int>>res(m, vector<int>(n,0));

        int i = 0; // row
        int j = 0; // col

        while(i<m && j<n){
            res[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= res[i][j];
            colSum[j] -= res[i][j];

            if(rowSum[i] == 0) i++;
            if(colSum[j] == 0) j++;
        }

        return res;
    }
};