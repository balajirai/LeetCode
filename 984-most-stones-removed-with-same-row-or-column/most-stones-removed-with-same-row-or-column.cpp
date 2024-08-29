class Solution {
private:
    void dfs(vector<vector<int>>& stones, int index, vector<bool>& vis){
        vis[index] = true;
        int row = stones[index][0], col = stones[index][1];
        for(int i=0; i<stones.size(); i++){
            if(!vis[i] && (stones[i][0] == row || stones[i][1] == col)){
                dfs(stones, i, vis);
            }
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), group = 0;
        vector<bool>vis(n, false);
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(stones, i, vis);
                group++;
            }
        }
        return n-group;
    }
};