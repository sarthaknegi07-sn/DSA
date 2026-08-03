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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newhead=root;
        TreeNode* newn=new TreeNode (val);
        if(root==NULL)
            return newn;
        while(root!=NULL){
            if(val > root->val){
                if(root->right==NULL){
                    root->right=newn;
                    break;
                }
                root=root->right;
            }
            else{
                if(root->left==NULL){
                    root->left=newn;
                    break;
                }
                root=root->left;
            }
        }
        return newhead;
    }
};