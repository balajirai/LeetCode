class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // degree of every nodes
        vector<int>degree(n, 0);
        for(auto &edge:roads){
            int u = edge[0];
            int v = edge[1];
            degree[u]++;
            degree[v]++;
        }

        sort(degree.begin(), degree.end());
        long long value = 1;
        long long sum = 0;

        for(int i=0; i<n; i++){
            sum += (degree[i]*value);
            value++;
        }

        return sum;
    }
};