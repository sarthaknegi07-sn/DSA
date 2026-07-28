/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool fn(TreeNode * p,TreeNode * q){
        if(p==NULL && q==NULL)
            return true;
        if(p==NULL || q==NULL)
            return false;
        if(p->val != q->val)
            return false;
        int leftTree=fn(p->left,q->right);
        int rightTree=fn(p->right,q->left);
        return leftTree && rightTree;
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return fn(root->left,root->right);
    }
};