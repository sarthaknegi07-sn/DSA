/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL || root==p || root==q)
            return root;
        
        TreeNode* left=lca(root->left,p,q);
        TreeNode* right=lca(root->right,p,q);

        // when coming upwards 
        // if left is null no matter what is right ,right will be returned
        if(left==NULL)  
            return right;
        else if(right==NULL)
            return left;
        // if equal
        else
            return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)  
            return nullptr;
        return lca(root,p,q);
    }
};