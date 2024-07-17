class Solution {
private:
    TreeNode* solve(TreeNode* root, unordered_set<int>st, vector<TreeNode*> &result){
        if(!root) return NULL;

        root->left = solve(root->left, st, result);
        root->right = solve(root->right, st, result);

        if(st.find(root->val) != st.end()){
            if(root->left) result.push_back(root->left);
            if(root->right) result.push_back(root->right);
            return NULL;
        }
        else return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int>st;

        for(int &num:to_delete){
            st.insert(num);
        }

        solve(root, st, result);

        if(st.find(root->val) == st.end()){
            result.push_back(root);
        }

        return result;
    }
};