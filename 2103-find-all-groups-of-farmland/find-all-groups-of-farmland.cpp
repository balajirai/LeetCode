class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size(), m = land[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j] == 1 && ((i == 0 || land[i-1][j] == 0) && (j == 0  || land[i][j-1] == 0))){
                    int new_i = i, new_j = j;
                    while(new_i < n && land[new_i][new_j] == 1)
                        new_i++;
                    new_i--;
                    while(new_j < m && land[new_i][new_j] == 1)
                        new_j++;
                    new_j--;

                    ans.push_back({i, j, new_i, new_j});
                    j = new_j;
                }
            }
        }  
        return ans;
    }
};