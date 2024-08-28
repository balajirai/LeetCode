class Solution {
private:
    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        if(i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size()) return true;
        if(grid2[i][j] != 1) return true;   // we need only land

        grid2[i][j] = -1;   // visited

        bool result = (grid1[i][j] == 1);  // grid1[i][j] must have 1

        result = result & checkSubIsland(grid1, grid2, i-1, j);     // Up
        result = result & checkSubIsland(grid1, grid2, i+1, j);     // Down
        result = result & checkSubIsland(grid1, grid2, i, j-1);     // Left
        result = result & checkSubIsland(grid1, grid2, i, j+1);     // Right

        return result;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int sub_islands = 0;
        int m = grid2.size(), n = grid2[0].size();  // rows and cols

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid2[i][j] == 1 && checkSubIsland(grid1, grid2, i, j)){
                    sub_islands++;
                }
            }
        }
        return sub_islands;
    }
};