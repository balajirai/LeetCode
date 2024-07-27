class Solution {
private:
    void floyd_warshell(vector<vector<int>>&dist){
        int n = dist.size();
        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][via]+dist[via][j]);
                }
            }
        }
    }

public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = 26;     // char - 'a' as index
        vector<vector<int>>distance(n, vector<int>(n, 1e9+7));

        for(int i=0; i<original.size(); i++){
            int src = original[i] - 'a';
            int tgt = changed[i] - 'a';

            distance[src][tgt] = min(distance[src][tgt], cost[i]);
        }

        floyd_warshell(distance);

        long long ans = 0;
        for(int i=0; i<source.size(); i++){
            if(source[i] == target[i]) continue;
            if(distance[source[i]-'a'][target[i]-'a'] == 1e9+7) return -1;
            ans += (long long)distance[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};