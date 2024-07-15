class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int>childSet;        // never be root
        int n = descriptions.size();

        for(int i=0; i<n; i++){
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            bool isLeft = descriptions[i][2];

            if(mp.find(parent) == mp.end()){
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end()){
                mp[child] = new TreeNode(child);
            }

            if(isLeft) mp[parent]->left = mp[child];
            else mp[parent]->right = mp[child];

            childSet.insert(child);
        }

        // finding the root
        for(int i=0; i<n; i++){
            int parent = descriptions[i][0];
            if(childSet.find(parent) == childSet.end()){
                return mp[parent];
            }
        }

        return NULL;
    }
};