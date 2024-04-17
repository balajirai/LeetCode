class Solution {
public:
    string ans;
    void solve(TreeNode *root,string z){
        char ch = root->val+'a';
        if(root->left == NULL && root->right == NULL){
            if(ans.size()==0) ans=ch+z;
            else if(ch+z < ans) ans = ch+z;
            return;
        }
        if(root->left) solve(root->left,ch+z);
        if(root->right) solve(root->right,ch+z);
    }
    string smallestFromLeaf(TreeNode* root) {
        string z="";
        ans = "";
        solve(root,z);
        return ans;
    }
};