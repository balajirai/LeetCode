class Solution {
public:
    vector<int>p;
    void post(TreeNode* root){
        if(root == NULL) return;
        post(root->left);
        post(root->right);
        p.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        post(root);
        return p;
    }
};