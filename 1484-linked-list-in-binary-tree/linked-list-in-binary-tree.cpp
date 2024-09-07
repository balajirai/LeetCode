class Solution {
private:
    bool check(ListNode* head, TreeNode* root){
        if(head == NULL) return true;
        if(root == NULL) return false;
        if(head->val != root->val) return false;
        return check(head->next, root->left) || check(head->next, root->right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        return check(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};