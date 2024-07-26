class Solution {
private:
    void floyd_warshell(vector<vector<int>>&dist){
        int n = dist.size();
        for(int via = 0; via < n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][via]+dist[via][j]);
                }
            }
        }
    }

    int resultCity(vector<vector<int>>&dist, int threshold){
        int ans = -1, n = dist.size();
        int leastCount = INT_MAX;

        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(i != j && dist[i][j] <= threshold) count++;
            }
            if(count <= leastCount){
                leastCount = count;
                ans = i;
            }
        }
        return ans;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>distance(n, vector<int>(n, 1e9+7));
        for(int i=0; i<n; i++) distance[i][i] = 0;

        for(auto &edge:edges){
            int u = edge[0], v = edge[1];
            int wt = edge[2];

            distance[u][v] = wt;
            distance[v][u] = wt;
        }

        floyd_warshell(distance);
        return resultCity(distance, distanceThreshold);
    }
};