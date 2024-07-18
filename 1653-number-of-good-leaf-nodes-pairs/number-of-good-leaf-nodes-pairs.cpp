class Solution {
private:
    void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>&adj, unordered_set<TreeNode*>&st){
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL) st.insert(root);  // leaf node
        if(prev != NULL){
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeGraph(root->left, root, adj, st);
        makeGraph(root->right, root, adj, st);
    }

public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>>adj;     // Graph
        unordered_set<TreeNode*>st;                        // leaf nodes

        makeGraph(root, NULL, adj, st);

        int count = 0;  // count of good pairs

        // BFS
        for(auto &leaf:st){
            queue<TreeNode*>q;
            unordered_set<TreeNode*>vis;
            q.push(leaf);
            vis.insert(leaf);

            // only go levels <= distance
            for(int level = 0; level <= distance; level++){
                int size = q.size();
                while(size--){      // level processed
                    TreeNode* curr = q.front();
                    q.pop();

                    if(curr != leaf && st.count(curr)){
                        count++;        // good pairs
                    }

                    for(auto &neighbour:adj[curr]){
                        if(!vis.count(neighbour)){
                            q.push(neighbour);
                            vis.insert(neighbour);
                        }
                    }
                }
            }
        }
        return count/2;
    }
};