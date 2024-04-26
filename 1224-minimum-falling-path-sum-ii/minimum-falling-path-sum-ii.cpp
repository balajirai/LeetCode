class Solution {
private:
    int solve(vector<vector<int>>& grid, int row, int col,vector<vector<int>>&dp){
        if(dp[row][col]!=-1) return dp[row][col];

        if(row == grid.size()) return 0;      // base case

        int ans = INT_MAX;
        for(int i=0; i<grid[0].size(); i++){
            if(i != col){
                ans = min(ans, grid[row][col] + solve(grid, row+1, i, dp));
            }
        }
        return dp[row][col] = ans;
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX, row = grid.size(), col = grid[0].size();
        if(grid[0].size()==1) return grid[0][0];
        vector<vector<int>>dp(row+1, vector<int>(col+1, -1));
        for(int j=0; j<col; j++){
            ans = min(ans, solve(grid, 0, j, dp));
        }
        return ans;
    }
};