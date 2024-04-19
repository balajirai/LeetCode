class Solution {
private:
    int m, n;   // m -> row, n -> col
    vector<vector<int>>direction = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    void dfs(int x, int y, vector<vector<bool>>&vis, vector<vector<char>>&grid){
        vis[x][y] = true;

        // checking for up down left right
        for(auto &dir:direction){
            int nx = x + dir[0];
            int ny = y + dir[1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] == '1'){
                dfs(nx, ny, vis, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));

        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i, j, vis, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};