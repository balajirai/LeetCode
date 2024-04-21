class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>a[n];
        for(auto i:edges){
            a[i[0]].push_back(i[1]);
            a[i[1]].push_back(i[0]);
        }
        queue<int>q;
        q.push(source);
        vector<int>ans(n,INT_MAX);
        ans[source]=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto i:a[front]){
                if(ans[i]>ans[front]){
                    ans[i]=ans[front];
                    q.push(i);
                }
            }
        }
        if(ans[destination]==INT_MAX){
            return false;
        }
        return true;
    }
};