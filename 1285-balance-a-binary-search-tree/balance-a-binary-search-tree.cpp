class Solution {
private:
    void findInorder(TreeNode* root, vector<int>&inorder){
        if(!root) return;
        findInorder(root->left, inorder);
        inorder.push_back(root->val);
        findInorder(root->right, inorder);
    }
    TreeNode* inorderToBST(int start, int end, vector<int>&inorder){
        // base case
        if(start > end) return NULL;

        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root->left = inorderToBST(start, mid-1, inorder);
        root->right = inorderToBST(mid+1, end, inorder);

        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        findInorder(root, inorder);
        return inorderToBST(0, inorder.size()-1, inorder);
    }
};