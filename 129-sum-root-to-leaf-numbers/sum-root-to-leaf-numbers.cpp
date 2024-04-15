class Solution {
public:

    void dfs(TreeNode* root, int &ans, int sum){
        if(root->left == NULL and root->right == NULL){
            sum = sum*10 + root->val;
            ans += sum;
            return;
        }
        sum = sum*10 + root->val;
        if(root->left) dfs(root->left,ans,sum);
        if(root->right) dfs(root->right,ans,sum);

    }

    int sumNumbers(TreeNode* root) {
        int ans = 0, sum = 0;
        dfs(root,ans,sum);
        return ans;
    }
};