class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int,double>>>adj;
        vector<double>result(n, 0);

        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        priority_queue<pair<double, int>>pq;       // max heap

        result[start_node] = 1;      // probability to reach start from start is 1 (100%)

        pq.push({1.0, start_node});

        // dijkstra algorithm (max probability)
        while(!pq.empty()){
            double currProb = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto &node:adj[currNode]){
                double adjProb = node.second;
                int adjNode = node.first;

                if(result[adjNode] < currProb*adjProb){
                    result[adjNode] = currProb*adjProb;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }
        return result[end_node];
    }
};